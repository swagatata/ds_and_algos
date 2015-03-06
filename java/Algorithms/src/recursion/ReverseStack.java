package recursion;

import java.util.Stack;

/**
 * Created by swagat on 17/02/15.
 */
public class ReverseStack {
    void reverseStack(Stack stack) {
        if (stack.empty()) {
            return;
        }

        Object topItem = stack.pop();

        reverseStack(stack);
        addAtBottom(stack, topItem);
    }

    private void addAtBottom(Stack stack, Object item) {
        if (stack.empty()) {
            stack.push(item);
            return;
        }

        Object topItem = stack.pop();

        addAtBottom(stack, item);
        stack.push(topItem);
    }

    public void test() {
        Stack<Integer> stack = new Stack<Integer>();

        for (int i = 0 ; i < 10 ; ++i) {
            stack.push(i);
        }

        System.out.println(stack);

        reverseStack(stack);

        System.out.println(stack);
    }
}
