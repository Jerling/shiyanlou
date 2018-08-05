public class Stringtest {
  public static void main(String args[]) {
    String s = new String("Java");
    String m = "java";
    System.out.println("The length of s is " + s.length());
    System.out.println("The length of m is " + s.length());
    System.out.println("equals test s and m : " + s.equals(m));
    System.out.println("equalsIgnoreCase test s and m : " + m.equalsIgnoreCase(s));

    String sm1 = s + m;
    String sm2 = sm1.concat(s);
    System.out.println("s + m : " + sm1);
    System.out.println("sm1.concat(s) : " + sm2);
    System.out.println("The first of s is " + s.charAt(0));
    System.out.println("The first index of a is  " + s.indexOf('a'));
    System.out.println("The first index of va is  " + s.indexOf("va"));
    System.out.println("The first index of a is  " + s.lastIndexOf('a'));
    System.out.println("The first index of va is sm2 " + sm2.lastIndexOf("va"));
    System.out.println("Th substring of 2: is " + sm2.substring(2));
    System.out.println("Th substring of 2-5: is " + sm2.substring(2, 5));

    String str = "first test last";
    System.out.println("trim test : " + str.trim());
  }
}
