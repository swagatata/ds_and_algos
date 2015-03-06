package tree;

import java.util.ArrayDeque;
import java.util.Queue;

/**
 * Created by swagat on 17/02/15.
 */
public class TreeTraversals {
    public static void levelOrder(BinaryTree tree) {
        if (tree == null) {
            return;
        }

        Queue<BinaryTree> bfsQ = new ArrayDeque();

        bfsQ.add(tree);
        int level = 0;

        while (!bfsQ.isEmpty()) {
            //No of nodes in the current level of the tree.
            int levelN = bfsQ.size();

            for (int i = 0 ; i < levelN ; ++i) {
                BinaryTree node = bfsQ.remove();

                System.out.print(node.getData() + " ");

                if (node.left != null) {
                    bfsQ.add(node.left);
                }

                if (node.right != null) {
                    bfsQ.add(node.right);
                }
            }
            System.out.println("");

            level++;
        }
    }
}
