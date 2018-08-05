public class Mathtest {
  public static void main(String args[]) {
    Float f = new Float(8.88);
    System.out.format("The sin of %.2f is %.4f%n" ,f.floatValue(), Math.sin(f.floatValue()));
    System.out.format("The cos of %.2f is %.4f%n" ,f.floatValue(), Math.cos(f.floatValue()));
    System.out.format("The asin of %.2f is %.4f%n" ,f.floatValue(), Math.asin(f.floatValue()));
    System.out.format("The acos of %.2f is %.4f%n" ,f.floatValue(), Math.acos(f.floatValue()));
    System.out.format("The atan of %.2f is %.4f%n" ,f.floatValue(), Math.atan(f.floatValue()));
    System.out.format("The pow(2) of %.2f is %.4f%n" ,f.floatValue(), Math.pow(f.floatValue(), 2));
    System.out.format("The sqrt of %.2f is %.4f%n" ,f.floatValue(), Math.sqrt(f.floatValue()));
    System.out.format("The abs of %.2f is %.4f%n" ,f.floatValue(), Math.abs(f.floatValue()));
    System.out.format("The ceil of %.2f is %.4f%n",f.floatValue(), Math.ceil(f.floatValue()));
    System.out.format("The floor of %.2f is %.4f%n" ,f.floatValue(), Math.floor(f.floatValue()));
    System.out.format("The ceil of %.2f is %.4f%n" ,f.floatValue(), Math.ceil(f.floatValue()));
    System.out.format("The rint of %.2f is %.4f%n" ,f.floatValue(), Math.rint(f.floatValue()));
    System.out.format("The random is %.4f%n" ,Math.random());
  }
}
