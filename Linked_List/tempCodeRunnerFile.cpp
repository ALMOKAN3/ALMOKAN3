Queue<int>* temp = queue.pull();
    while (temp != nullptr){
        cout << temp->val << endl;
        temp = temp->right;
    }