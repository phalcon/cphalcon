--TEST--
Phalcon\Security::derviveKey() - https://github.com/phalcon/cphalcon/pull/1759
--SKIPIF--
<?php
include('skipif.inc');
if (!function_exists('hash')) {
	die('skip hash extension is required');
}
?>
--FILE--
<?php

if (!function_exists('hash_pbkdf2')) {
	/**
	* @see https://raw.github.com/rchouinard/hash_pbkdf2-compat/master/src/hash_pbkdf2.php
	*/
	function hash_pbkdf2($algo, $password, $salt, $iterations, $length = 0, $raw_output = false)
	{
		$salt_len = strlen($salt);

		$hash_len = strlen(hash($algo, null, true));
		if ($length == 0) {
			$length = $hash_len;
		}

		$output = '';
		$block_count = ceil($length / $hash_len);
		for ($block = 1; $block <= $block_count; ++$block) {
			$key1 = $key2 = hash_hmac($algo, $salt . pack('N', $block), $password, true);
			for ($iteration = 1; $iteration < $iterations; ++$iteration) {
				$key2 ^= $key1 = hash_hmac($algo, $key1, $password, true);
			}

			$output .= $key2;
		}

		return substr(($raw_output) ? $output : bin2hex($output), 0, $length);
	}
}

$data = array(
	array('password', 'salt', 'sha256', 1000, 0),
	array('passwordpasswordpasswordpassword', 'salt', 'sha256', 1000, 0),
	array('pass', 'saltsaltsaltsaltsaltsalt', 'sha256', 1000, 0),

	array('password', 'salt', 'md5', 1000, 0),
	array('passwordpasswordpasswordpassword', 'salt', 'md5', 1000, 0),
	array('pass', 'saltsaltsaltsaltsaltsalt', 'md5', 1000, 0),

	array('password', 'salt', 'sha256', 1000, 100),
	array('passwordpasswordpasswordpassword', 'salt', 'sha256', 1000, 100),
	array('pass', 'saltsaltsaltsaltsaltsalt', 'sha256', 1000, 100),

	array('password', 'salt', 'md5', 1000, 100),
	array('passwordpasswordpasswordpassword', 'salt', 'md5', 1000, 100),
	array('pass', 'saltsaltsaltsaltsaltsalt', 'md5', 1000, 100),
);

foreach ($data as $x) {
	list($password, $salt, $hash, $iterations, $size) = $x;

	echo base64_encode(Phalcon\Security::deriveKey($password, $salt, $hash, $iterations, $size)), PHP_EOL;
	echo base64_encode(Phalcon\Security::pbkdf2($password, $salt, $hash, $iterations, $size)), PHP_EOL;
	echo base64_encode(hash_pbkdf2($hash, $password, $salt, $iterations, $size, true)), PHP_EOL;
	echo PHP_EOL;
}

?>
--EXPECT--
YywoEuRtRgQQK6dhjp1tfS+BKPYma0oDJk0qBGC33LM=
YywoEuRtRgQQK6dhjp1tfS+BKPYma0oDJk0qBGC33LM=
YywoEuRtRgQQK6dhjp1tfS+BKPYma0oDJk0qBGC33LM=

r3eEgknShf3hVVj+TrfAU95sPZs+P/XTnSAnQP2MNCs=
r3eEgknShf3hVVj+TrfAU95sPZs+P/XTnSAnQP2MNCs=
r3eEgknShf3hVVj+TrfAU95sPZs+P/XTnSAnQP2MNCs=

SwZ64fSrqiUaa3qoCNO6zeUOaIEZoZLC0VM17/RD8jo=
SwZ64fSrqiUaa3qoCNO6zeUOaIEZoZLC0VM17/RD8jo=
SwZ64fSrqiUaa3qoCNO6zeUOaIEZoZLC0VM17/RD8jo=

jRiZRqMtiDYioWrhivBjLw==
jRiZRqMtiDYioWrhivBjLw==
jRiZRqMtiDYioWrhivBjLw==

N8SjZ1QZOyOaIT8ZqNme3w==
N8SjZ1QZOyOaIT8ZqNme3w==
N8SjZ1QZOyOaIT8ZqNme3w==

nGw5KSo1seqVVbuJ1meAFQ==
nGw5KSo1seqVVbuJ1meAFQ==
nGw5KSo1seqVVbuJ1meAFQ==

YywoEuRtRgQQK6dhjp1tfS+BKPYma0oDJk0qBGC33LOIs7ETH3Qby+sCVByMLpe9i+1iq2QlVC5FUStzEvRA68biH0NWpe3zLPA5Tg1b6UDg6TDP4h44o/+U4o0mwj+sdwGskg==
YywoEuRtRgQQK6dhjp1tfS+BKPYma0oDJk0qBGC33LOIs7ETH3Qby+sCVByMLpe9i+1iq2QlVC5FUStzEvRA68biH0NWpe3zLPA5Tg1b6UDg6TDP4h44o/+U4o0mwj+sdwGskg==
YywoEuRtRgQQK6dhjp1tfS+BKPYma0oDJk0qBGC33LOIs7ETH3Qby+sCVByMLpe9i+1iq2QlVC5FUStzEvRA68biH0NWpe3zLPA5Tg1b6UDg6TDP4h44o/+U4o0mwj+sdwGskg==

r3eEgknShf3hVVj+TrfAU95sPZs+P/XTnSAnQP2MNCuUz8OVZby/aDaWnzafny4pGF1vaDorb9mMWnX8gBb4JeV1Nv/hCO4ScMsSvvFT3l/GmBgd5AwDipO/1DGiQmMFS9xn7Q==
r3eEgknShf3hVVj+TrfAU95sPZs+P/XTnSAnQP2MNCuUz8OVZby/aDaWnzafny4pGF1vaDorb9mMWnX8gBb4JeV1Nv/hCO4ScMsSvvFT3l/GmBgd5AwDipO/1DGiQmMFS9xn7Q==
r3eEgknShf3hVVj+TrfAU95sPZs+P/XTnSAnQP2MNCuUz8OVZby/aDaWnzafny4pGF1vaDorb9mMWnX8gBb4JeV1Nv/hCO4ScMsSvvFT3l/GmBgd5AwDipO/1DGiQmMFS9xn7Q==

SwZ64fSrqiUaa3qoCNO6zeUOaIEZoZLC0VM17/RD8jr5XBg29RTZMdUBkjxT4avV6MkILUAa9898uYo1mhx6kyy7QYgXNeMUCX5wleCvmTvqGSUluIjuGStK7TDMAB71903cHg==
SwZ64fSrqiUaa3qoCNO6zeUOaIEZoZLC0VM17/RD8jr5XBg29RTZMdUBkjxT4avV6MkILUAa9898uYo1mhx6kyy7QYgXNeMUCX5wleCvmTvqGSUluIjuGStK7TDMAB71903cHg==
SwZ64fSrqiUaa3qoCNO6zeUOaIEZoZLC0VM17/RD8jr5XBg29RTZMdUBkjxT4avV6MkILUAa9898uYo1mhx6kyy7QYgXNeMUCX5wleCvmTvqGSUluIjuGStK7TDMAB71903cHg==

jRiZRqMtiDYioWrhivBjL1eR1eexq7CrF1fSjONAVhQDNRBZlElfkUIHDwZAJ9bfnbjj1vvQBCrL+3Y37h4Qs8rLTSTb3tHrJtM9W2Qmq2uPZMjc9AR38S+jmLHf5rS8NygnRg==
jRiZRqMtiDYioWrhivBjL1eR1eexq7CrF1fSjONAVhQDNRBZlElfkUIHDwZAJ9bfnbjj1vvQBCrL+3Y37h4Qs8rLTSTb3tHrJtM9W2Qmq2uPZMjc9AR38S+jmLHf5rS8NygnRg==
jRiZRqMtiDYioWrhivBjL1eR1eexq7CrF1fSjONAVhQDNRBZlElfkUIHDwZAJ9bfnbjj1vvQBCrL+3Y37h4Qs8rLTSTb3tHrJtM9W2Qmq2uPZMjc9AR38S+jmLHf5rS8NygnRg==

N8SjZ1QZOyOaIT8ZqNme3+jiDst+4MEKyCr4jpKI0EyqT1VaFElbIa0TXkIbRvkZekm7K6nR4IbG9kJN+LOd09+iHoogHBy0PEPh0zmAihXa+ux8GnBN4bQEbXjMN5zGhVjAjA==
N8SjZ1QZOyOaIT8ZqNme3+jiDst+4MEKyCr4jpKI0EyqT1VaFElbIa0TXkIbRvkZekm7K6nR4IbG9kJN+LOd09+iHoogHBy0PEPh0zmAihXa+ux8GnBN4bQEbXjMN5zGhVjAjA==
N8SjZ1QZOyOaIT8ZqNme3+jiDst+4MEKyCr4jpKI0EyqT1VaFElbIa0TXkIbRvkZekm7K6nR4IbG9kJN+LOd09+iHoogHBy0PEPh0zmAihXa+ux8GnBN4bQEbXjMN5zGhVjAjA==

nGw5KSo1seqVVbuJ1meAFfE19/TLomq3c928tJhyUwRaaKhZy9vUTGsX4mBurk484s08Tn0YjYFZ1lilO5NJfbFNDuK6X6GwIY+0xI4DdzLl9OGJR3fLhvR+UDpEz5RTiygxsA==
nGw5KSo1seqVVbuJ1meAFfE19/TLomq3c928tJhyUwRaaKhZy9vUTGsX4mBurk484s08Tn0YjYFZ1lilO5NJfbFNDuK6X6GwIY+0xI4DdzLl9OGJR3fLhvR+UDpEz5RTiygxsA==
nGw5KSo1seqVVbuJ1meAFfE19/TLomq3c928tJhyUwRaaKhZy9vUTGsX4mBurk484s08Tn0YjYFZ1lilO5NJfbFNDuK6X6GwIY+0xI4DdzLl9OGJR3fLhvR+UDpEz5RTiygxsA==

