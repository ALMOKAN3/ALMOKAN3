#include <iostream>
#include <bitset>
#include <fstream>
#include <vector>
#include <thread>
#include <mutex>
#include <time.h>
#include <chrono>
using namespace std;

#define RULE_SIZE 8
#define SIZE 512
#define NUMBER_OF_RULSE 10

class CellularAutomation{
    private:
    mutex mtx;
    public:
    void saveToFile(int imagewidth, int imageheight, int** imageAsNoumber, string filePath){
        ofstream MyFile;
        MyFile.open(filePath, ios::out | ios::trunc);
        MyFile << "p2\n";
        MyFile << imagewidth << " " << imageheight << "\n";
        MyFile << "255\n";

        for(int row = 0; row < imagewidth; row++){
                for(int col = 0; col < imageheight; col++){
                    MyFile << imageAsNoumber[row][col]*255 << " ";
                }
                MyFile << "\n";
            }

            MyFile.close();
    }

    int applRule(int** imageAsNoumber, int imagewidth, int midCol, int provRow, string rule){
        int leftCol = (midCol-1) < 0 ? imagewidth-1 : midCol-1;
        int rightCol = (midCol+1) >= imagewidth ? 0 : midCol+1;
        int provLeft = imageAsNoumber[provRow][leftCol];
        int provCenter = imageAsNoumber[provRow][midCol];
        int provRight = imageAsNoumber[provRow][rightCol];
        int ruleIndex = (provLeft << 2) | (provCenter << 1) | (provRight);
        return (rule[RULE_SIZE-1-ruleIndex] == '1' ? 1 : 0);
    }

    void solveSequenatall(int imagewidth, int imageheight, int** imageAsNoumber, string rule){
        for(int row = 1; row < imagewidth; row++){
            for(int col = 0; col < imageheight; col++){
                imageAsNoumber[row][col] = this->applRule(imageAsNoumber, imagewidth, col, row-1, rule);
            }
        }
        this_thread::sleep_for(chrono::seconds(1));
    }

    //set
        void reset(int imagewidth, int imageheight, int** imageAsNoumber){
            for(int j = 0; j < imageheight; j++){
                imageAsNoumber[0][j] = 0;
            }
            imageAsNoumber[0][imagewidth/2] = 1;
        }

    void seqSolution(){
        int imagewidth = SIZE;
        int imageheight = SIZE;
        int* imageAsNoumber[SIZE];
        for(int i = 0; i < imageheight; i++){
            imageAsNoumber[i] = new int[imagewidth];
        }

        for(int ruleID = 0; ruleID <= NUMBER_OF_RULSE; ruleID++){
            string rule = bitset<RULE_SIZE>(ruleID).to_string();

            // sequnatall
            this->reset(imagewidth, imageheight, imageAsNoumber);

            string filePathSeq = "pgn" + rule + "Seq.pgn";
            this->solveSequenatall(imagewidth, imageheight, imageAsNoumber, rule);
            this->saveToFile(imagewidth, imageheight, imageAsNoumber, filePathSeq);


            // pareall
            // reset(imagewidth, imageheight, imageASNoumber);


        }

        // clean
        for(int i = 0; i < imageheight; i++){
            delete[] imageAsNoumber[i];
        }
    }

    void worker(int imagewidth, int imageheight, int& ruleID){
        int* imageAsNoumber[SIZE];
        for(int i = 0; i < imageheight; i++){
            imageAsNoumber[i] = new int[imagewidth];
        }
        CellularAutomation cellularAutomation;

        while(true){
            this->mtx.lock();
            string rule = bitset<RULE_SIZE>(ruleID).to_string();
            ruleID = ruleID+1;
            if(ruleID > NUMBER_OF_RULSE){
                this->mtx.unlock();
                break;
            }
            this->mtx.unlock();

            // sequnatall
            cellularAutomation.reset(imagewidth, imageheight, imageAsNoumber);

            string filePathSeq = rule + "Parl.pgm";
            cellularAutomation.solveSequenatall(imagewidth, imageheight, imageAsNoumber, rule);
            cellularAutomation.saveToFile(imagewidth, imageheight, imageAsNoumber, filePathSeq);
        }

        // clean
        for(int i = 0; i < imageheight; i++){
            delete[] imageAsNoumber[i];
        }
    }

    void parSolution(){
        int imagewidth = SIZE;
        int imageheight = SIZE;
        int ruleID = 0;

        int numberOfThreads = 10;

        vector<thread> listOfThread;
        for(int i = 0; i < numberOfThreads; i++){
            listOfThread.push_back(thread(&CellularAutomation::worker, this, imagewidth, imageheight, ref(ruleID)));
        }

        for(auto& thread : listOfThread){
            thread.join();
        }
    }
};

int main(){

    CellularAutomation cellularAutomation;

    clock_t start = clock();
    cellularAutomation.seqSolution();
    clock_t end = clock();
    double timeSpend = (end - start) / CLOCKS_PER_SEC * 1000;
    cout << "This to finish seqSolution was: " << timeSpend << "ms" << endl;

    cout << "main thread ID: " << this_thread::get_id() << endl;

    start = clock();
    cellularAutomation.parSolution();
    end = clock();
    timeSpend = (end - start) / CLOCKS_PER_SEC * 1000;
    cout << "This to finish parallel was: " << timeSpend << "ms" << endl;

    return 0;
}