# ECE 3574, Project 2 integration testing - short example
import pexpect
import pexpect.replwrap as replwrap
import unittest
import os
	
# the vtcalc executable
cmd = './vtcalc'

class TestExecuteFromCommandLine(unittest.TestCase):
		
	def test_addition(self):
		args = ' -e ' + ' "3 4 +" '
		(output, retcode) = pexpect.run(cmd+args, withexitstatus=True, extra_args=args)
		self.assertEqual(retcode, 0)
		self.assertEqual(output.strip(), b"7")

	def test_subtraction(self):
		args = ' -e ' + ' "12 100 -" '
		(output, retcode) = pexpect.run(cmd+args, withexitstatus=True, extra_args=args)
		self.assertEqual(retcode, 0)
		self.assertEqual(output.strip(), b"-88")
		

class TestExecuteFromFile(unittest.TestCase):
		
	def test_sub(self):
		args = ' /vagrant/example1.txt'
		(output, retcode) = pexpect.run(cmd+args, withexitstatus=True, extra_args=args)
		self.assertEqual(retcode, 0)
		self.assertEqual(output.strip(), b"7")

	def test_error(self):
		args = ' /there/is/no/such/file'
		(output, retcode) = pexpect.run(cmd+args, withexitstatus=True, extra_args=args)
		self.assertNotEqual(retcode, 0)
		self.assertTrue(output.strip().startswith(b'ERROR'))


		
# run the tests
unittest.main()
