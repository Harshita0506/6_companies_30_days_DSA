int nodes=1;
        preorder+=',';
        for(int i=0;i<preorder.size();i++){
            if(preorder[i]!=',')continue;//comma seperated values of nodes
            nodes--; //after taking each node decrease value of left nodes
            if(nodes<0)return false;
            if(preorder[i-1]!='#')nodes+=2;//if current node is not null means it will 2 childs si increase by 2;
        }
        return nodes==0;