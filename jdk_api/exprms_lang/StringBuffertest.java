public class StringBuffertest {
  public static void main(String args[]) {
    StringBuffer s = new StringBuffer("I");
    s.append(" java");
    s.insert(1, " love");
    System.out.println("s : " + s.toString());
    System.out.println("The length of s : " + s.length());
    s.setCharAt(0,'i');
    System.out.println("s : " + s.toString());
    System.out.println("The reverse of s : " + s.reverse());
    System.out.println("After delete : " + s.delete(0,5));
    System.out.println("After replace: " + s.replace(0,4,"java"));
  }
}
