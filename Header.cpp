#pragma once
#include<string>
#include"Header.h"


int calcs::fstf(int i, string s) {
	int fst = 0;
	for (int j = i - 1; j >= 0; j--) {
		if (s[j] == '*' || s[j] == '+' || s[j] == '/' || s[j] == '(' || s[j] == ')') {
			return fst;
		}
		fst++;
	}
	return fst;
}
int calcs::secf(int i, string s) {
	int sec = 0;
	for (int j = i + 1; j < s.length(); j++) {
		if (s[j] == '*' || s[j] == '+' || s[j] == '/' || s[j] == ')') {
			return sec;
		}
		sec++;
	}
	return sec;
}
int calcs::bozorgyab(string adad1, string adad2) {
	if ((adad1.length() > adad2.length()) && adad1[0] > 48)
		return 1;
	if ((adad1.length() < adad2.length()) && adad2[0] > 48)
		return 2;
	for (int i = 0; i <= adad1.length() - 1; i++) {
		if (adad1[i] > adad2[i])
			return 1;
		if (adad2[i] > adad1[i])
			return 2;
	}
	return 3;
}
string calcs::sumf(string adad1, string adad2, string sum = "") {
	int tempsum = 0, y = 0, ashar1, ashar2, asharmax, asharnumber, k1, k2, toolashar1 = 0, toolashar2 = 0;
	bool ashar = false, manfi1 = false, manfi2 = false;
	if (adad1[0] == '-') {
		manfi1 = true;
		adad1.erase(0, 1);
	}
	if (adad2[0] == '-') {
		manfi2 = true;
		adad2.erase(0, 1);
	}
	for (int a = adad1.length() - 1; a >= 0; a--) {
		if (adad1[a] == '.') {
			ashar = true;
			ashar1 = a;
			toolashar1 = adad1.length() - 1 - a;
		}
	}
	for (int a = adad2.length() - 1; a >= 0; a--) {
		if (adad2[a] == '.') {
			ashar2 = a;
			ashar = true;
			asharnumber = 2;
			toolashar2 = adad2.length() - 1 - a;
		}
	}
	if (ashar) {
		if (toolashar1 == toolashar2)
			asharnumber = 0;
		else if (toolashar1 > toolashar2)
			asharnumber = 1;
		if (asharnumber == 0) {
			adad1.erase(ashar1, 1);
			adad2.erase(ashar2, 1);
		}
		else if (asharnumber == 1) {
			for (k2 = 0; k2 < (toolashar1 - toolashar2); k2++) {
				adad2.insert(adad2.length(), "0");
			}
			if (toolashar2 != 0)
				adad2.erase(ashar2, 1);
			adad1.erase(ashar1, 1);
			toolashar2 += k2;
		}
		else if (asharnumber == 2) {
			for (k1 = 0; k1 < (toolashar2 - toolashar1); k1++) {
				adad1.insert(adad1.length(), "0");
			}
			if (toolashar1 != 0)
				adad1.erase(ashar1, 1);
			adad2.erase(ashar2, 1);
			toolashar1 += k1;
		}
	}
	while (adad1.length() != adad2.length()) {
		if (adad1.length() > adad2.length())
			adad2.insert(0, "0");
		else if (adad2.length() > adad1.length())
			adad1.insert(0, "0");
	}
	sum.erase(0, 1);
	bool manfi = false;
	string swaptemp;
	if ((manfi1 && !manfi2) || (!manfi1 && manfi2)) {
		for (int i = 0; i <= adad1.length() - 1; i++) {
			if (adad1[i] > adad2[i]) {
				if (manfi1)
					manfi = true;
				break;
			}
			if (adad2[i] > adad1[i]) {
				swaptemp = adad1;
				adad1 = adad2;
				adad2 = swaptemp;
				if (manfi2)
					manfi = true;
				break;
			}
		}
		for (int i = adad1.length() - 1; i >= 0; i--) {
			tempsum = adad1[i] - adad2[i] + y;
			y = 0;
			if (tempsum < 0) {
				y = -1;
				tempsum += 10;
			}
			sum.insert(0, to_string(tempsum));
		}
		if (manfi)
			sum.insert(0, "-");
	}
	else {
		for (int i = adad1.length() - 1; i >= -1; i--) {
			if (i != -1)
				tempsum = adad1[i] - 48 + adad2[i] - 48 + y;
			else if (i == -1 && y == 0)
				break;
			else
				tempsum = y;
			y = 0;
			if (tempsum >= 10) {
				y = tempsum / 10;
				tempsum %= 10;
			}
			string a = to_string(tempsum);
			sum.insert(0, a);
		}
		if (manfi1 && manfi2)
			sum.insert(0, "-");
	}
	if (ashar)
		sum.insert(sum.length() - toolashar1, ".");
	if (sum[0] == '-')
		while (sum[1] == '0' && sum[1] > 47)
			sum.erase(1, 1);
	else
		while (sum[0] == '0' && sum[1] > 47)
			sum.erase(0, 1);
	while (ashar && sum[sum.length() - 1] == '0')
		sum.erase(sum.length() - 1, 1);
	if (sum[sum.length() - 1] == '.')
		sum.erase(sum.length() - 1, 1);
	return sum;
}
string calcs::multi(string adad1, string adad2) {
	string swaptemp = "", mult = "", sum = "0", sefrmult = "";
	bool ashar = false, manfi1 = false, manfi2 = false;
	int toolashar1 = 0, toolashar2 = 0, tempmult = 0, y = 0;
	if (adad1[0] == '-') {
		manfi1 = true;
		adad1.erase(0, 1);
	}
	if (adad2[0] == '-') {
		manfi2 = true;
		adad2.erase(0, 1);
	}
	for (int a = adad1.length() - 1; a >= 0; a--) {
		if (adad1[a] == '.') {
			ashar = true;
			toolashar1 = adad1.length() - 1 - a;
			adad1.erase(a, 1);
		}
	}
	for (int a = adad2.length() - 1; a >= 0; a--) {
		if (adad2[a] == '.') {
			ashar = true;
			toolashar2 = adad2.length() - 1 - a;
			adad2.erase(a, 1);
		}
	}
	mult.erase(0, 1);
	sefrmult.erase(0, 1);
	for (int i = adad2.length() - 1; i >= 0; i--) {
		for (int j = adad1.length() - 1; j >= -1; j--) {
			if (j == -1 && y == 0)
				break;
			else if (j == -1 && y > 0)
				tempmult = y;
			else
				tempmult = (adad1[j] - 48) * (adad2[i] - 48) + y;
			y = 0;
			if (tempmult > 9) {
				y = tempmult / 10;
				tempmult %= 10;
			}
			mult.insert(0, to_string(tempmult));
		}
		mult.insert(mult.length(), sefrmult);
		sum = sumf(sum, mult);
		mult = "";
		mult.erase(0, 1);
		sefrmult.insert(0, "0");
	}
	if (ashar) {
		string ab = sumf(to_string(toolashar1), to_string(toolashar2));
		while (sum.length() <= stoi(ab)) {
			sum.insert(0, "0");
		}
		sum.insert(sum.length() - stoi(ab), ".");
	}
	if (((manfi1 && !manfi2) || (!manfi1 && manfi2)) && sum != "0")
		sum.insert(0, "-");
	while (ashar && sum[sum.length() - 1] == '0')
		sum.erase(sum.length() - 1, 1);
	if (sum[sum.length() - 1] == '.')
		sum.erase(sum.length() - 1, 1);
	if (ashar) {
		int k = 0;
		for (; k < sum.length(), sum[k] != '.'; k++) {
		}
		if (sum.length() - 1 - k > 5) {
			if (sum[k + 1] == '9' && sum[k + 2] == '9' && sum[k + 3] == '9' && sum[k + 4] == '9' && sum[k + 5] == '9' && sum[k + 6] == '9') {
				sum = sumf(sum, "1");
				sum.erase(k, sum.length() - k);
			}
		}

	}
	return sum;
}
string calcs::div(string adad1, string adad2) {
	string tempdiv = "", answer = "";
	int bozorg = 0, j = 0, shomar = -1, ashar = 0, ashar1 = 0, ashar2 = 0, toolashar1 = 0, toolashar2 = 0, sefr = 0;
	bool manfi1 = false, manfi2 = false;
	tempdiv.erase(0, 1);
	if (adad1[0] == '-') {
		manfi1 = true;
		adad1.erase(0, 1);
	}
	if (adad2[0] == '-') {
		manfi2 = true;
		adad2.erase(0, 1);
	}
	for (int a = adad1.length() - 1; a >= 0; a--) {
		if (adad1[a] == '.') {
			while (adad1[adad1.length() - 1] == '0')
				adad1.erase(adad1.length() - 1, 1);
			toolashar1 = adad1.length() - 1 - a;
			adad1.erase(a, 1);
		}
	}
	for (int a = adad2.length() - 1; a >= 0; a--) {
		if (adad2[a] == '.') {
			while (adad2[adad2.length() - 1] == '0')
				adad2.erase(adad2.length() - 1, 1);
			toolashar2 = adad2.length() - 1 - a;
			adad2.erase(a, 1);
		}
	}
	while (adad1[0] == '0' && adad1[1] >= '0' && adad1[1] <= '9')
		adad1.erase(0, 1);
	while (adad2[0] == '0' && adad2[1] >= '0' && adad2[1] <= '9')
		adad2.erase(0, 1);
	if (adad1 == "0")
		return 0;
	int toolashar = toolashar1 - toolashar2;
	bozorg = bozorgyab(adad1, adad2);
	while (bozorg != 1 && bozorg != 3) {
		ashar++;
		adad1.insert(adad1.length(), "0");
		bozorg = bozorgyab(adad1, adad2);
	}
	bozorg = 0;
	adad1.insert(adad1.length(), "00000000");
	if (adad1.length() < adad2.length())
		adad1 = adad1;
	else {
		answer.erase(0, 1);
		while (bozorg != 1 && bozorg != 3) {
			shomar++;
			tempdiv = adad1.substr(0, adad2.length() + shomar);
			bozorg = bozorgyab(tempdiv, adad2);
		}
		for (int i = adad2.length() + shomar - 1; i <= adad1.length() - 1; ) {
			j = -1;
			while (bozorg != 2) {
				j++;
				bozorg = bozorgyab(tempdiv, multi(adad2, to_string(j)));
			}
			j--;
			answer.insert(answer.length(), to_string(j));
			string tempmin = multi(adad2, to_string(j).insert(0, "-"));
			tempdiv = sumf(tempdiv, tempmin);
			bozorg = 0;
			int z = 0;
			while (bozorg != 2) {
				if (tempdiv[0] == '0')
					tempdiv.erase(0, 1);
				i++;
				if (i >= adad1.length())
					break;
				tempdiv.insert(tempdiv.length(), adad1.substr(i, 1));
				bozorg = bozorgyab(adad2, tempdiv);
				if (bozorg == 1)
					answer.insert(answer.length(), "0");
			}
			bozorg = 0;
			if (i >= adad1.length())
				break;
		}
		for (int i = 1; i <= ashar + toolashar; i++)
			answer.insert(0, "0");
		answer.insert(answer.length() - 8 - ashar - toolashar, ".");
		while (answer[answer.length() - 1] == '0' && answer[answer.length() - 1] != '.')
			answer.erase(answer.length() - 1, 1);
		if (answer[answer.length() - 1] == '.') {
			answer.erase(answer.length() - 1, 1);
			ashar = false;
		}
		while (answer[0] == '0' && answer[1] != '.')
			answer.erase(0, 1);
		if (answer[0] == '.')
			answer.insert(0, "0");
		if ((manfi1 && !manfi2) || (!manfi1 && manfi2))
			answer.insert(0, "-");
		return answer;
	}
}
string calcs::calc(string s) {
	for (int i = 0; i < s.length(); i++) {
		if ((s[i] == 'r' && s[i + 1] == 'o' && s[i + 2] == 't') || s[i] == 'l' && s[i + 1] == 'o' && s[i + 2] == 'g') {
			int fst = 0, temp = 0, j = 0;
			for (int j = i + 4; !(temp == 0 && s[j] == ','); j++) {
				if (s[j] == '(')
					temp++;
				if (s[j] == ')')
					temp--;
				fst++;
			}
			temp = 1;
			for (j = i + 6 + fst; temp != 0; j++) {
				if (s[j] == '(')
					temp++;
				if (s[j] == ')')
					temp--;
			}
			int sec = j - (i + 6 + fst);
			if (s[i] == 'r' && s[i + 1] == 'o' && s[i + 2] == 't') {
				double y = stod(calc(s.substr(i + 4, fst))), x = stod(calc(s.substr(i + 5 + fst, sec))), z = 1, a = 0, b = 0;
				a = x / (2 * y);
				for (int k = 1; b - a != 0; k++) {
					for (int j = 1; j < y; j++)
						z *= a;
					b = a;
					a = ((y - 1) * a + x / z) / y;
					z = 1;
				}
				s.replace(i, 7 + sec + fst, to_string(a));
			}
			else if (s[i] == 'l' && s[i + 1] == 'o' && s[i + 2] == 'g') {
				double x = stod(calc(s.substr(i + 4, fst))), y = stod(calc(s.substr(i + 5 + fst, sec))), n = 0, sum1 = 0, sum2 = 0;
				x = (x - 1) / (x + 1);
				n = x;
				for (int i = 1; i <= 100000; i += 2) {
					sum1 += n / i;
					n *= x * x;
				}
				y = (y - 1) / (y + 1);
				n = y;
				for (int i = 1; i <= 100000; i += 2) {
					sum2 += n / i;
					n *= y * y;
				}
				s.replace(i, 6 + sec + fst, to_string(sum1 / sum2));
			}
		}
		else if (s[i] == 'l' && s[i + 1] == 'o' && s[i + 2] == 'g') {
			int fst = secf(i + 2, s), sec = secf(i + 3 + fst, s);
			double x = stod(s.substr(i + 3, fst)), y = stod(s.substr(i + 4 + fst, sec)), n = 0, sum1 = 0, sum2 = 0;
			x = (x - 1) / (x + 1);
			n = x;
			for (int i = 1; i <= 100000; i += 2) {
				sum1 += n / i;
				n *= x * x;
			}
			y = (y - 1) / (y + 1);
			n = y;
			for (int i = 1; i <= 100000; i += 2) {
				sum2 += n / i;
				n *= y * y;
			}
			s.replace(i, 6 + sec + fst, to_string(sum1 / sum2));
		}
	}
	//parantez
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '(') {
			int aval = i, temp = 1, j = i + 1;
			while (temp != 0) {
				if (s[j] == '(')
					temp++;
				if (s[j] == ')')
					temp--;
				j++;
			}
			int dovom = j - 1;
			if (s[aval] == '(')
				s.erase(aval, 1);
			if (s[dovom - 1] == ')')
				s.erase(dovom - 1, 1);
			s.replace(aval, dovom - aval - 1, calc(s.substr(aval, dovom - aval - 1)));
		}
	}
	//tavabe
	for (int i = 0; i < s.length(); i++) {
		if (('a' <= s[i] && s[i] <= 'z') || s[i] == '!' || s[i] == '^') {
			if (s[i] == 'e')
				s.replace(i, 1, "2.7182818");
			else if (s[i] == 'p')
				s.replace(i, 1, "3.14159265359");
			else if (s[i] == '!') {
				double fst = fstf(i, s), n = stoi(s.substr(i - fst, fst)), sum = 1;
				if (n == '0')
					sum = 1;
				for (int j = 2; j <= n; j++)
					sum *= j;
				s.replace(i - fst, fst + 1, to_string(sum));
			}
			else if (s[i] == '^') {
				double fst = fstf(i, s), sec = secf(i, s), sum = 1, a = stoi(s.substr(i - fst, fst)), n = stoi(s.substr(i + 1, sec));
				for (int j = 1; j <= n; j++)
					sum *= a;
				s.replace(i - fst, fst + 1 + sec, to_string(sum));
			}
			else if (s[i] == 'l' && s[i + 1] == 'n') {
				int k = 0;
				int fst = secf(i + 1, s);
				double x = stod(s.substr(i + 2, fst)) - 1, sum = 0, n = x;
				x = (x - 1) / (x + 1);
				n = x;
				for (int i = 1; i <= 100000; i += 2) {
					sum += n / i;
					n *= x * x;
				}
				s.replace(i, fst + 2, to_string(2 * sum));
			}

			else {
				int fst = secf(i + 2, s);
				double x = stod(s.substr(i + 3, fst));
				while ((s[i] == 's' || s[i] == 'c' || s[i] == 't') && (x >= 6.28318530718))
					x -= 6.28318530718;
				while ((s[i] == 's' || s[i] == 'c' || s[i] == 't') && (x <= -6.28318530718))
					x += 6.28318530718;
				if (s[i] == 's' && s[i + 1] == 'i' && s[i + 2] == 'n') {
					x = x - (x * x * x / 6) + ((x * x * x * x * x) / 120) - ((x * x * x * x * x * x * x) / 5040) + ((x * x * x * x * x * x * x * x * x) / 362880) - ((x * x * x * x * x * x * x * x * x * x * x) / 39916800) + ((x * x * x * x * x * x * x * x * x * x * x * x * x) / 6227020800) - ((x * x * x * x * x * x * x * x * x * x * x * x * x * x * x) / 1307674368000) + ((x * x * x * x * x * x * x * x * x * x * x * x * x * x * x * x * x) / 355687428096000) - ((x * x * x * x * x * x * x * x * x * x * x * x * x * x * x * x * x * x * x) / 121645100408832000);
					s.replace(i, fst + 3, to_string(x));
				}
				else if (s[i] == 'c' && s[i + 1] == 'o' && s[i + 2] == 's') {
					x = 1 - ((x * x) / 2) + ((x * x * x * x) / 24) - ((x * x * x * x * x * x) / 720) + ((x * x * x * x * x * x * x * x) / 40320) - ((x * x * x * x * x * x * x * x * x * x) / 3628800) + ((x * x * x * x * x * x * x * x * x * x * x * x) / 479001600) - ((x * x * x * x * x * x * x * x * x * x * x * x * x * x) / 87178291200) + ((x * x * x * x * x * x * x * x * x * x * x * x * x * x * x * x) / 20922789888000) - ((x * x * x * x * x * x * x * x * x * x * x * x * x * x * x * x * x * x) / 6402373705728000);
					s.replace(i, fst + 3, to_string(x));
				}
				if (s[i] == 't' && s[i + 1] == 'a' && s[i + 2] == 'n') {
					double a = x - (x * x * x / 6) + ((x * x * x * x * x) / 120) - ((x * x * x * x * x * x * x) / 5040) + ((x * x * x * x * x * x * x * x * x) / 362880) - ((x * x * x * x * x * x * x * x * x * x * x) / 39916800) + ((x * x * x * x * x * x * x * x * x * x * x * x * x) / 6227020800) - ((x * x * x * x * x * x * x * x * x * x * x * x * x * x * x) / 1307674368000) + ((x * x * x * x * x * x * x * x * x * x * x * x * x * x * x * x * x) / 355687428096000) - ((x * x * x * x * x * x * x * x * x * x * x * x * x * x * x * x * x * x * x) / 121645100408832000);
					double b = 1 - ((x * x) / 2) + ((x * x * x * x) / 24) - ((x * x * x * x * x * x) / 720) + ((x * x * x * x * x * x * x * x) / 40320) - ((x * x * x * x * x * x * x * x * x * x) / 3628800) + ((x * x * x * x * x * x * x * x * x * x * x * x) / 479001600) - ((x * x * x * x * x * x * x * x * x * x * x * x * x * x) / 87178291200) + ((x * x * x * x * x * x * x * x * x * x * x * x * x * x * x * x) / 20922789888000) - ((x * x * x * x * x * x * x * x * x * x * x * x * x * x * x * x * x * x) / 6402373705728000);
					x = a / b;
					s.replace(i, fst + 3, to_string(x));
				}
				if (s[i] == 'c' && s[i + 1] == 'o' && s[i + 2] == 't') {
					double a = x - (x * x * x / 6) + ((x * x * x * x * x) / 120) - ((x * x * x * x * x * x * x) / 5040) + ((x * x * x * x * x * x * x * x * x) / 362880) - ((x * x * x * x * x * x * x * x * x * x * x) / 39916800) + ((x * x * x * x * x * x * x * x * x * x * x * x * x) / 6227020800) - ((x * x * x * x * x * x * x * x * x * x * x * x * x * x * x) / 1307674368000) + ((x * x * x * x * x * x * x * x * x * x * x * x * x * x * x * x * x) / 355687428096000) - ((x * x * x * x * x * x * x * x * x * x * x * x * x * x * x * x * x * x * x) / 121645100408832000);
					double b = 1 - ((x * x) / 2) + ((x * x * x * x) / 24) - ((x * x * x * x * x * x) / 720) + ((x * x * x * x * x * x * x * x) / 40320) - ((x * x * x * x * x * x * x * x * x * x) / 3628800) + ((x * x * x * x * x * x * x * x * x * x * x * x) / 479001600) - ((x * x * x * x * x * x * x * x * x * x * x * x * x * x) / 87178291200) + ((x * x * x * x * x * x * x * x * x * x * x * x * x * x * x * x) / 20922789888000) - ((x * x * x * x * x * x * x * x * x * x * x * x * x * x * x * x * x * x) / 6402373705728000);
					x = b / a;
					s.replace(i, fst + 3, to_string(x));
				}
			}
		}
	}
	//menha va manfi
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '-') {
			if (i == 0) {
				s.replace(0, 1, "-1*");
				i += 2;
			}
			else if (s[i + 1] >= '0' && s[i + 1] <= '9' && s[i - 1] >= '0' && s[i - 1] <= '9') {
				s.replace(i, 1, "+-");
				i++;
			}
			else if (s[i - 1] == '*' || s[i - 1] == '+' || s[i - 1] == '/' || s[i - 1] == '(') {
				s.replace(i, 1, "-1*");
				i += 2;
			}
			else {
				s.replace(i, 1, "+-1*");
				i += 3;
			}
		}
	}
	//zarbVAtaghsim
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '*') {
			int fst = fstf(i, s);
			int sec = secf(i, s);
			string tempzarb = multi(s.substr(i - fst, fst).c_str(), s.substr(i + 1, sec).c_str());
			s.replace(i - fst, fst + sec + 1, tempzarb);
			i = i - fst + tempzarb.length() - 1;
		}
		if (s[i] == '/') {
			int fst = fstf(i, s);
			int sec = secf(i, s);
			string tempdiv = div(s.substr(i - fst, fst).c_str(), s.substr(i + 1, sec).c_str());
			s.replace(i - fst, fst + sec + 1, tempdiv);
			i = i - fst + tempdiv.length() - 1;
		}
	}
	//jam
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '+') {
			int fst = fstf(i, s);
			int sec = secf(i, s);
			string tempdiv = sumf(s.substr(i - fst, fst).c_str(), s.substr(i + 1, sec).c_str());
			s.replace(i - fst, fst + sec + 1, tempdiv);
			i = i - fst + tempdiv.length() - 1;
		}
	}
	return s;
}