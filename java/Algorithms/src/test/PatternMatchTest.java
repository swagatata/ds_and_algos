package test;

import dp.LongestCommonSubsequence;
import string.PatternMatcher;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

/**
 * Created by swagat on 24/02/15.
 */
public class PatternMatchTest {
    private static final String testsFileName = "input/patternmatch";
    private final File inputFile;
    private String [] texts, patterns;

    public PatternMatchTest() {
        inputFile = new File(testsFileName);

        BufferedReader reader = null;
        try {
            reader = new BufferedReader(new FileReader(inputFile));
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }

        Scanner scanner = new Scanner(reader);
        int nTestCases = scanner.nextInt();
        scanner.nextLine();

        texts = new String[nTestCases];
        patterns = new String[nTestCases];
        for (int i = 0 ; i < nTestCases ; ++i) {
            texts[i] = scanner.nextLine();
            patterns[i] = scanner.nextLine();
        }
    }

    public void boyerMooreTest() {
        for (int i = 0 ; i < texts.length ; ++i) {
            System.out.println(texts[i]);
            System.out.println(patterns[i]);

            PatternMatcher matcher = new PatternMatcher(texts[i]);

            System.out.println(matcher.boyerMooreMatch(patterns[i]));
        }
    }

    public void kmpTest() {
        for (int i = 0 ; i < texts.length ; ++i) {
            System.out.println(texts[i]);
            System.out.println(patterns[i]);

            PatternMatcher matcher = new PatternMatcher(texts[i]);

            matcher.kmp(patterns[i]);
            //System.out.println(matcher.kmp(patterns[i]));
        }
    }

    public void lcsTest() {
        for (int i = 0 ; i < texts.length ; ++i) {
            System.out.println(texts[i]);
            System.out.println(patterns[i]);

            List<Character> text = new ArrayList<>();
            List<Character> pattern = new ArrayList<>();

            for (char c : texts[i].toCharArray()) {
                text.add(c);
            }
            for (char c : patterns[i].toCharArray()) {
                pattern.add(c);
            }

            LongestCommonSubsequence lcs = new LongestCommonSubsequence(text, pattern);
            System.out.println(lcs.lcsDP());
        }
    }
}
