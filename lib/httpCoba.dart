import 'package:http/http.dart' as http;

class Kirim {
  /// fungsi untuk mengirimkan data ke esp
  Future send() async {
    var url = 'http://192.168.11.4/dpot?a=100';
    var response = await http.get(url);
    print(response.statusCode);
    print(response.body);
    if (response.statusCode == 200) {
      print('sukses');
    } else {
      print('gagal');
    }
  }
}
