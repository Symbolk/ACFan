/**
 * Create a Qzone object html
 */



/**
 * @author ����
 *
 */

import java.net.URLConnection;
import java.net.HttpURLConnection;
import java.net.JarURLConnection;
import java.net.URL;
import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.InputStream;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;

import javax.swing.text.html.HTML;

import org.python.util.PythonInterpreter;

 

public class GetQzoneHtml {

    public static void main(String []args){

       try{

           /*

            *   ����һ

            *      

           URL url = new URL("http://www.sina.com.cn");

           URLConnection urlcon = url.openConnection();

           InputStream is = urlcon.getInputStream();

            */

           

           /*

            * ������

            * 

            * URL url = new URL("http://www.yhfund.com.cn");

           HttpURLConnection urlcon = (HttpURLConnection)url.openConnection();

           InputStream is = urlcon.getInputStream();

            */

           

           

           

           /*

            * ������

            * URL url = new URL("http://www.yhfund.com.cn");

           InputStream is = url.openStream();

            */

           long begintime = System.currentTimeMillis();

           

           PythonInterpreter interpreter = new PythonInterpreter();
           //interpreter.execfile("C:\\Python27\\programs\\input.py");
           interpreter.execfile("C:\\Users\\Carwinwiskey\\Desktop\\Algorithm\\workspace\\GetQzone\\src\\PythonForLogin.py");
           URL url = new URL("http://user.qzone.qq.com/319471708/infocenter");

           HttpURLConnection urlcon = (HttpURLConnection)url.openConnection();

           urlcon.connect();         //��ȡ����

           InputStream is = urlcon.getInputStream();
           
           
           
           BufferedReader reader = new BufferedReader(new InputStreamReader(
      				System.in));
      		//String filename = reader.readLine();
      		String filename = "QzoneHtml.txt";
      		
      		// Write file to disk
      		FileOutputStream outfile = new FileOutputStream(filename);
      		byte[] bytebuffer = new byte[1024];
      		int size;
      		while ((size = is.read(bytebuffer)) != -1) {
      			outfile.write(bytebuffer, 0, size);
      		}
      		outfile.flush();
      		outfile.close();
      		
      		
           

           BufferedReader buffer = new BufferedReader(new InputStreamReader(is));

           StringBuffer bs = new StringBuffer();

           String l = null;

           while((l=buffer.readLine())!=null){

               bs.append(l).append("/n");

           }
           

           //File file = new File("HTML");
           //createFile(file, bs);
           
           System.out.println(bs.toString());
           

           

           //System.out.println(" content-encode��"+urlcon.getContentEncoding());

           //System.out.println(" content-length��"+urlcon.getContentLength());

           //System.out.println(" content-type��"+urlcon.getContentType());

           //System.out.println(" date��"+urlcon.getDate());

       

           

           System.out.println("�ܹ�ִ��ʱ��Ϊ��"+(System.currentTimeMillis()-begintime)+"����");

        }catch(IOException e){

           System.out.println(e);

       }

       
    }

}





/*
public class GetQzoneHtml {
	
	private 

	
	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}
	
	public return_type name() {
		
	}

}


	private static void createFile(File file, StringBuffer buffer) {
		try {
			File newFile = new File(file.getAbsolutePath() + ".txt");
			if (newFile.exists())// ���ڣ���ɾ��
				if (!newFile.delete())// ɾ���ɹ��򴴽�
				{
					System.err.println("ɾ���ļ�" + newFile + "ʧ��");
				}
			if (newFile.createNewFile()) {// �����ɹ�����д���ļ�����
				PrintWriter p = new PrintWriter(new FileOutputStream(newFile
						.getAbsolutePath()));
				p.write(buffer.toString());
				p.close();
			} else {
				System.err.println("�����ļ���" + newFile + "ʧ��");
			}
		} catch (Exception e) {
			e.printStackTrace();
		}
	}	
*/
