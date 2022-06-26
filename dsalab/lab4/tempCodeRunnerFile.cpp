Node* curr = root; 
        Node* prev = NULL; 

        while (curr != NULL && curr->data != value) { 
            prev = curr; 
            if (value < curr->data) 
                curr = curr->pLeft;
            else
                curr = curr->pRight; 
        } 

        

        if (curr->pLeft == NULL || curr->pRight == NULL) { 
            Node* newCurr; 
            if (curr->pLeft == NULL) newCurr = curr->pRight; 
            else newCurr = curr->pLeft; 

            if (prev == NULL) return node; 
            if (curr == prev->pLeft) prev->pLeft = newCurr; 
            else prev->pRight = newCurr; 
            free(curr); 
        } 
        else { 
            Node* p = NULL; 
            Node* temp; 

            temp = curr->pRight; 
            while (temp->pLeft != NULL) { 
                p = temp; 
                temp = temp->pLeft; 
            } 
            if (p != NULL){ 
                p->pLeft = temp->pRight;
            } 
            else{
                curr->pRight = temp->pRight; 
            }
            curr->data = temp->data; 
            free(temp); 
        } 

         int balance = getBalance(node); 
        //cout << "balance: " << balance << endl;
        // Left Left Case  
        if (balance > 1 && value < node->pLeft->data){
            return rightRotate(node);
        }

        // Right Right Case  
        if (balance < -1 && value >= node->pRight->data)
            return leftRotate(node);

        // Left Right Case  
        if (balance > 1 && value >= node->pLeft->data)
        {
            node->pLeft = leftRotate(node->pLeft);
            return rightRotate(node);
        }
        // Right Left Case  
        if (balance < -1 && value < node->pRight->data)
        {
            node->pRight = rightRotate(node->pRight);
            return leftRotate(node);
        }
        return node;