package tree;

/**
 * Created by swagat on 17/02/15.
 */
public class Tests {
    public static void runTests() {
        runTreeBuilderTest();
        runTreeDoublerTest();
    }

    private static void runTreeDoublerTest() {
        BinaryTree<Integer> binaryTree = BinaryTree.buildTree(10);

        TreeTraversals.levelOrder(binaryTree);

        BinaryTree binaryTreeDoubled = (new TreeDoubler()).doubleTree(binaryTree);

        TreeTraversals.levelOrder(binaryTreeDoubled);

        System.out.println("runTreeDoublerTest successful.");
    }

    private static void runTreeBuilderTest() {
        BinaryTree<Integer> binaryTree = BinaryTree.buildTree(10);

        TreeTraversals.levelOrder(binaryTree);

        System.out.println("runTreeBuilderTest successful.");
    }
}
