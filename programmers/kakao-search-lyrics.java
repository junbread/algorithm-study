/** 효율성 풀이 통과가 안되는 코드 */
package programmers;

import java.util.HashMap;
import java.util.ArrayList;

class KakaoSearchLyrics {
    class Trie {
        public HashMap<Integer, Integer> count = new HashMap<>();
        public HashMap<Character, Trie> next = new HashMap<>();

        void insert(String str) {
            if (str.length() == 0)
                return;

            count.put(str.length(), count.getOrDefault(str.length(), 0) + 1);

            Trie nextNode = next.getOrDefault(str.charAt(0), new Trie());
            nextNode.insert(str.substring(1));

            next.put(str.charAt(0), nextNode);
        }

        int count(String str, int length) {
            if (str.length() == 0)
                return count.getOrDefault(length, 0);
            if (next.get(str.charAt(0)) == null)
                return 0;
            else
                return next.get(str.charAt(0)).count(str.substring(1), length - 1);
        }

    }

    String reverse(String str) {
        return new StringBuffer(str).reverse().toString();
    }

    public int[] solution(String[] words, String[] queries) {
        ArrayList<Integer> res = new ArrayList<>();

        Trie forward = new Trie();
        Trie backward = new Trie();
        for (int i = 0; i < words.length; i++) {
            forward.insert(words[i]);
            backward.insert(reverse(words[i]));
        }

        for (int i = 0; i < queries.length; i++) {
            if (queries[i].endsWith("?"))
                res.add(forward.count(queries[i].replaceAll("\\?", ""), queries[i].length()));
            else
                res.add(backward.count(reverse(queries[i].replaceAll("\\?", "")), queries[i].length()));
        }

        int[] answer = new int[res.size()];
        for (int i = 0; i < res.size(); i++)
            answer[i] = res.get(i);
        return answer;
    }

    public static void main(String[] args) {
        String[] words = { "frodo", "front", "frost", "frozen", "frame", "kakao" };
        String[] queries = { "fro??", "????o", "fr???", "fro???", "pro?" };

        KakaoSearchLyrics l = new KakaoSearchLyrics();
        System.out.println(l.solution(words, queries));
    }
}