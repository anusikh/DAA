bool inBST(Node *root,int min,int max)
{
    if(!root)
        return true;    //NULL is not a node to be checked. So, return true always
    if(root->data>min && root->data<max)
        return (inBST(root->left,min,root->data) && inBST(root->right,root->data,max));

    return false;
}

bool checkBST(Node* root) {
    if(!root)
        return true;
    if(inBST(root->left,0,root->data) && inBST(root->right,root->data,10000))
        return true;
    return false;
}


//use min and max over here and keep updating the values while iterating