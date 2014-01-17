import unittest
import fizzbuzz

class TestFizzBuzz(unittest.TestCase):
    def test_is_fizz(self):
        self.assertTrue(fizzbuzz.is_fizz(6))
        self.assertFalse(fizzbuzz.is_fizz(5))
        self.assertFalse(fizzbuzz.is_fizz(-1))
    def test_is_buzz(self):
        self.assertTrue(fizzbuzz.is_buzz(10))
        self.assertFalse(fizzbuzz.is_buzz(13))
        self.assertFalse(fizzbuzz.is_buzz(-1))
    def test_fizzbuzz(self):
        self.assertEqual("FizzBuzz", fizzbuzz.fizzbuzz(30))
        self.assertEqual("Fizz",     fizzbuzz.fizzbuzz(6))
        self.assertEqual("Buzz",     fizzbuzz.fizzbuzz(10))
        self.assertEqual(-1,         fizzbuzz.fizzbuzz(-1))

if __name__ == '__main__':
    unittest.main()
