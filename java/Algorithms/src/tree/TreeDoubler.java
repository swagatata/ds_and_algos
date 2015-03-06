package tree;

/**
 * Created by swagat on 17/02/15.
 */
public class TreeDoubler {
    public BinaryTree doubleTree(BinaryTree tree) {
        if (tree == null) {
            return tree;
        }

        BinaryTree left = doubleTree(tree.left);
        BinaryTree right = doubleTree(tree.right);

        BinaryTree duplicate = new BinaryTree();
        duplicate.setData(tree.getData());

        duplicate.left = tree.left;
        tree.left = duplicate;

        return tree;
    }
}
