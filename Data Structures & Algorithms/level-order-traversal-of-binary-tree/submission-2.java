/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */

class Solution {
    public List<List<Integer>> levelOrder(TreeNode root) {

        List<List<Integer>> master = new ArrayList<>();
        if(root == null) return master;

        Queue<TreeNode> q = new ArrayDeque<>();
        q.offer(root);

        while(!q.isEmpty()){
            int size = q.size();
            List<Integer> answer = new ArrayList<>();

            for(int i = 0; i < size; i++){
                TreeNode front = q.poll();

                answer.add(front.val);
                if(front.left != null) q.offer(front.left);
                if(front.right != null) q.offer(front.right);
            }
            master.add(answer);
        }

        return master;
    }
}
