<?php return array (
  0 => 
  array (
    'type' => 'comment',
    'value' => '**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 *',
    'file' => '/app/phalcon/Security/Random.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Security',
    'file' => '/app/phalcon/Security/Random.zep',
    'line' => 84,
    'char' => 2,
  ),
  2 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Phalcon\\Security\\Random
 *
 * Secure random number generator class.
 *
 * Provides secure random number generator which is suitable for generating
 * session key in HTTP cookies, etc.
 *
 * It supports following secure random number generators:
 *
 * - random_bytes (PHP 7)
 * - libsodium
 * - openssl, libressl
 * - /dev/urandom
 *
 * `Phalcon\\Security\\Random` could be mainly useful for:
 *
 * - Key generation (e.g. generation of complicated keys)
 * - Generating random passwords for new user accounts
 * - Encryption systems
 *
 *```php
 * $random = new \\Phalcon\\Security\\Random();
 *
 * // Random binary string
 * $bytes = $random->bytes();
 *
 * // Random hex string
 * echo $random->hex(10); // a29f470508d5ccb8e289
 * echo $random->hex(10); // 533c2f08d5eee750e64a
 * echo $random->hex(11); // f362ef96cb9ffef150c9cd
 * echo $random->hex(12); // 95469d667475125208be45c4
 * echo $random->hex(13); // 05475e8af4a34f8f743ab48761
 *
 * // Random base62 string
 * echo $random->base62(); // z0RkwHfh8ErDM1xw
 *
 * // Random base64 string
 * echo $random->base64(12); // XfIN81jGGuKkcE1E
 * echo $random->base64(12); // 3rcq39QzGK9fUqh8
 * echo $random->base64();   // DRcfbngL/iOo9hGGvy1TcQ==
 * echo $random->base64(16); // SvdhPcIHDZFad838Bb0Swg==
 *
 * // Random URL-safe base64 string
 * echo $random->base64Safe();           // PcV6jGbJ6vfVw7hfKIFDGA
 * echo $random->base64Safe();           // GD8JojhzSTrqX7Q8J6uug
 * echo $random->base64Safe(8);          // mGyy0evy3ok
 * echo $random->base64Safe(null, true); // DRrAgOFkS4rvRiVHFefcQ==
 *
 * // Random UUID
 * echo $random->uuid(); // db082997-2572-4e2c-a046-5eefe97b1235
 * echo $random->uuid(); // da2aa0e2-b4d0-4e3c-99f5-f5ef62c57fe2
 * echo $random->uuid(); // 75e6b628-c562-4117-bb76-61c4153455a9
 * echo $random->uuid(); // dc446df1-0848-4d05-b501-4af3c220c13d
 *
 * // Random number between 0 and $len
 * echo $random->number(256); // 84
 * echo $random->number(256); // 79
 * echo $random->number(100); // 29
 * echo $random->number(300); // 40
 *
 * // Random base58 string
 * echo $random->base58();   // 4kUgL2pdQMSCQtjE
 * echo $random->base58();   // Umjxqf7ZPwh765yR
 * echo $random->base58(24); // qoXcgmw4A9dys26HaNEdCRj9
 * echo $random->base58(7);  // 774SJD3vgP
 *```
 *
 * This class partially borrows SecureRandom library from Ruby
 *
 * @link http://ruby-doc.org/stdlib-2.2.2/libdoc/securerandom/rdoc/SecureRandom.html
 *',
    'file' => '/app/phalcon/Security/Random.zep',
    'line' => 85,
    'char' => 5,
  ),
  3 => 
  array (
    'type' => 'class',
    'name' => 'Random',
    'abstract' => 0,
    'final' => 0,
    'definition' => 
    array (
      'methods' => 
      array (
        0 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'base58',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'len',
              'const' => 0,
              'data-type' => 'int',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Security/Random.zep',
                'line' => 107,
                'char' => 42,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Security/Random.zep',
              'line' => 107,
              'char' => 42,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Security/Random.zep',
                  'line' => 109,
                  'char' => 21,
                ),
                'name' => 'base',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'string',
                      'value' => '123456789ABCDEFGHJKLMNPQRSTUVWXYZabcdefghijkmnopqrstuvwxyz',
                      'file' => '/app/phalcon/Security/Random.zep',
                      'line' => 110,
                      'char' => 71,
                    ),
                    'file' => '/app/phalcon/Security/Random.zep',
                    'line' => 110,
                    'char' => 71,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'int',
                      'value' => '58',
                      'file' => '/app/phalcon/Security/Random.zep',
                      'line' => 111,
                      'char' => 15,
                    ),
                    'file' => '/app/phalcon/Security/Random.zep',
                    'line' => 111,
                    'char' => 15,
                  ),
                  2 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'len',
                      'file' => '/app/phalcon/Security/Random.zep',
                      'line' => 113,
                      'char' => 9,
                    ),
                    'file' => '/app/phalcon/Security/Random.zep',
                    'line' => 113,
                    'char' => 9,
                  ),
                ),
                'file' => '/app/phalcon/Security/Random.zep',
                'line' => 113,
                'char' => 10,
              ),
              'file' => '/app/phalcon/Security/Random.zep',
              'line' => 114,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Generates a random base58 string
     *
     * If $len is not specified, 16 is assumed. It may be larger in future.
     * The result may contain alphanumeric characters except 0, O, I and l.
     *
     * It is similar to `Phalcon\\Security\\Random::base64()` but has been
     * modified to avoid both non-alphanumeric characters and letters which
     * might look ambiguous when printed.
     *
     *```php
     * $random = new \\Phalcon\\Security\\Random();
     *
     * echo $random->base58(); // 4kUgL2pdQMSCQtjE
     *```
     *
     * @see    \\Phalcon\\Security\\Random:base64
     * @link   https://en.wikipedia.org/wiki/Base58
     * @throws Exception If secure random number generator is not available or unexpected partial read
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'string',
                'mandatory' => 0,
                'file' => '/app/phalcon/Security/Random.zep',
                'line' => 108,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Security/Random.zep',
            'line' => 108,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Security/Random.zep',
          'line' => 107,
          'last-line' => 134,
          'char' => 19,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'base62',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'len',
              'const' => 0,
              'data-type' => 'int',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Security/Random.zep',
                'line' => 135,
                'char' => 42,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Security/Random.zep',
              'line' => 135,
              'char' => 42,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Security/Random.zep',
                  'line' => 137,
                  'char' => 21,
                ),
                'name' => 'base',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'string',
                      'value' => '0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz',
                      'file' => '/app/phalcon/Security/Random.zep',
                      'line' => 138,
                      'char' => 75,
                    ),
                    'file' => '/app/phalcon/Security/Random.zep',
                    'line' => 138,
                    'char' => 75,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'int',
                      'value' => '62',
                      'file' => '/app/phalcon/Security/Random.zep',
                      'line' => 139,
                      'char' => 15,
                    ),
                    'file' => '/app/phalcon/Security/Random.zep',
                    'line' => 139,
                    'char' => 15,
                  ),
                  2 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'len',
                      'file' => '/app/phalcon/Security/Random.zep',
                      'line' => 141,
                      'char' => 9,
                    ),
                    'file' => '/app/phalcon/Security/Random.zep',
                    'line' => 141,
                    'char' => 9,
                  ),
                ),
                'file' => '/app/phalcon/Security/Random.zep',
                'line' => 141,
                'char' => 10,
              ),
              'file' => '/app/phalcon/Security/Random.zep',
              'line' => 142,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Generates a random base62 string
     *
     * If $len is not specified, 16 is assumed. It may be larger in future.
     *
     * It is similar to `Phalcon\\Security\\Random::base58()` but has been
     * modified to provide the largest value that can safely be used in URLs
     * without needing to take extra characters into consideration because it is
     * [A-Za-z0-9].
     *
     *```php
     * $random = new \\Phalcon\\Security\\Random();
     *
     * echo $random->base62(); // z0RkwHfh8ErDM1xw
     *```
     *
     * @see    \\Phalcon\\Security\\Random:base58
     * @throws Exception If secure random number generator is not available or unexpected partial read
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'string',
                'mandatory' => 0,
                'file' => '/app/phalcon/Security/Random.zep',
                'line' => 136,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Security/Random.zep',
            'line' => 136,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Security/Random.zep',
          'line' => 135,
          'last-line' => 158,
          'char' => 19,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'base64',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'len',
              'const' => 0,
              'data-type' => 'int',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Security/Random.zep',
                'line' => 159,
                'char' => 42,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Security/Random.zep',
              'line' => 159,
              'char' => 42,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'fcall',
                'name' => 'base64_encode',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'mcall',
                      'variable' => 
                      array (
                        'type' => 'variable',
                        'value' => 'this',
                        'file' => '/app/phalcon/Security/Random.zep',
                        'line' => 162,
                        'char' => 18,
                      ),
                      'name' => 'bytes',
                      'call-type' => 1,
                      'parameters' => 
                      array (
                        0 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'variable',
                            'value' => 'len',
                            'file' => '/app/phalcon/Security/Random.zep',
                            'line' => 162,
                            'char' => 28,
                          ),
                          'file' => '/app/phalcon/Security/Random.zep',
                          'line' => 162,
                          'char' => 28,
                        ),
                      ),
                      'file' => '/app/phalcon/Security/Random.zep',
                      'line' => 163,
                      'char' => 9,
                    ),
                    'file' => '/app/phalcon/Security/Random.zep',
                    'line' => 163,
                    'char' => 9,
                  ),
                ),
                'file' => '/app/phalcon/Security/Random.zep',
                'line' => 163,
                'char' => 10,
              ),
              'file' => '/app/phalcon/Security/Random.zep',
              'line' => 164,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Generates a random base64 string
     *
     * If $len is not specified, 16 is assumed. It may be larger in future.
     * The length of the result string is usually greater of $len.
     * Size formula: 4 * ($len / 3) rounded up to a multiple of 4.
     *
     *```php
     * $random = new \\Phalcon\\Security\\Random();
     *
     * echo $random->base64(12); // 3rcq39QzGK9fUqh8
     *```
     *
     * @throws Exception If secure random number generator is not available or unexpected partial read
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'string',
                'mandatory' => 0,
                'file' => '/app/phalcon/Security/Random.zep',
                'line' => 160,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Security/Random.zep',
            'line' => 160,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Security/Random.zep',
          'line' => 159,
          'last-line' => 185,
          'char' => 19,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'base64Safe',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'len',
              'const' => 0,
              'data-type' => 'int',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Security/Random.zep',
                'line' => 186,
                'char' => 46,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Security/Random.zep',
              'line' => 186,
              'char' => 46,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'padding',
              'const' => 0,
              'data-type' => 'bool',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'bool',
                'value' => 'false',
                'file' => '/app/phalcon/Security/Random.zep',
                'line' => 186,
                'char' => 68,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Security/Random.zep',
              'line' => 186,
              'char' => 68,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'declare',
              'data-type' => 'variable',
              'variables' => 
              array (
                0 => 
                array (
                  'variable' => 's',
                  'file' => '/app/phalcon/Security/Random.zep',
                  'line' => 188,
                  'char' => 14,
                ),
              ),
              'file' => '/app/phalcon/Security/Random.zep',
              'line' => 190,
              'char' => 11,
            ),
            1 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 's',
                  'expr' => 
                  array (
                    'type' => 'fcall',
                    'name' => 'strtr',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'fcall',
                          'name' => 'base64_encode',
                          'call-type' => 1,
                          'parameters' => 
                          array (
                            0 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'mcall',
                                'variable' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'this',
                                  'file' => '/app/phalcon/Security/Random.zep',
                                  'line' => 192,
                                  'char' => 22,
                                ),
                                'name' => 'base64',
                                'call-type' => 1,
                                'parameters' => 
                                array (
                                  0 => 
                                  array (
                                    'parameter' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'len',
                                      'file' => '/app/phalcon/Security/Random.zep',
                                      'line' => 192,
                                      'char' => 33,
                                    ),
                                    'file' => '/app/phalcon/Security/Random.zep',
                                    'line' => 192,
                                    'char' => 33,
                                  ),
                                ),
                                'file' => '/app/phalcon/Security/Random.zep',
                                'line' => 193,
                                'char' => 13,
                              ),
                              'file' => '/app/phalcon/Security/Random.zep',
                              'line' => 193,
                              'char' => 13,
                            ),
                          ),
                          'file' => '/app/phalcon/Security/Random.zep',
                          'line' => 193,
                          'char' => 14,
                        ),
                        'file' => '/app/phalcon/Security/Random.zep',
                        'line' => 193,
                        'char' => 14,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => '+/',
                          'file' => '/app/phalcon/Security/Random.zep',
                          'line' => 194,
                          'char' => 15,
                        ),
                        'file' => '/app/phalcon/Security/Random.zep',
                        'line' => 194,
                        'char' => 15,
                      ),
                      2 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => '-_',
                          'file' => '/app/phalcon/Security/Random.zep',
                          'line' => 196,
                          'char' => 9,
                        ),
                        'file' => '/app/phalcon/Security/Random.zep',
                        'line' => 196,
                        'char' => 9,
                      ),
                    ),
                    'file' => '/app/phalcon/Security/Random.zep',
                    'line' => 196,
                    'char' => 10,
                  ),
                  'file' => '/app/phalcon/Security/Random.zep',
                  'line' => 196,
                  'char' => 10,
                ),
              ),
              'file' => '/app/phalcon/Security/Random.zep',
              'line' => 198,
              'char' => 11,
            ),
            2 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 's',
                  'expr' => 
                  array (
                    'type' => 'fcall',
                    'name' => 'preg_replace',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => '#[^a-z0-9_=-]+#i',
                          'file' => '/app/phalcon/Security/Random.zep',
                          'line' => 199,
                          'char' => 29,
                        ),
                        'file' => '/app/phalcon/Security/Random.zep',
                        'line' => 199,
                        'char' => 29,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => '',
                          'file' => '/app/phalcon/Security/Random.zep',
                          'line' => 200,
                          'char' => 13,
                        ),
                        'file' => '/app/phalcon/Security/Random.zep',
                        'line' => 200,
                        'char' => 13,
                      ),
                      2 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 's',
                          'file' => '/app/phalcon/Security/Random.zep',
                          'line' => 202,
                          'char' => 9,
                        ),
                        'file' => '/app/phalcon/Security/Random.zep',
                        'line' => 202,
                        'char' => 9,
                      ),
                    ),
                    'file' => '/app/phalcon/Security/Random.zep',
                    'line' => 202,
                    'char' => 10,
                  ),
                  'file' => '/app/phalcon/Security/Random.zep',
                  'line' => 202,
                  'char' => 10,
                ),
              ),
              'file' => '/app/phalcon/Security/Random.zep',
              'line' => 204,
              'char' => 10,
            ),
            3 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'not',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'padding',
                  'file' => '/app/phalcon/Security/Random.zep',
                  'line' => 204,
                  'char' => 21,
                ),
                'file' => '/app/phalcon/Security/Random.zep',
                'line' => 204,
                'char' => 21,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'fcall',
                    'name' => 'rtrim',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 's',
                          'file' => '/app/phalcon/Security/Random.zep',
                          'line' => 205,
                          'char' => 27,
                        ),
                        'file' => '/app/phalcon/Security/Random.zep',
                        'line' => 205,
                        'char' => 27,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => '=',
                          'file' => '/app/phalcon/Security/Random.zep',
                          'line' => 205,
                          'char' => 30,
                        ),
                        'file' => '/app/phalcon/Security/Random.zep',
                        'line' => 205,
                        'char' => 30,
                      ),
                    ),
                    'file' => '/app/phalcon/Security/Random.zep',
                    'line' => 205,
                    'char' => 31,
                  ),
                  'file' => '/app/phalcon/Security/Random.zep',
                  'line' => 206,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Security/Random.zep',
              'line' => 208,
              'char' => 14,
            ),
            4 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 's',
                'file' => '/app/phalcon/Security/Random.zep',
                'line' => 208,
                'char' => 17,
              ),
              'file' => '/app/phalcon/Security/Random.zep',
              'line' => 209,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Generates a random URL-safe base64 string
     *
     * If $len is not specified, 16 is assumed. It may be larger in future.
     * The length of the result string is usually greater of $len.
     *
     * By default, padding is not generated because "=" may be used as a URL
     * delimiter. The result may contain A-Z, a-z, 0-9, "-" and "_". "=" is also
     * used if $padding is true. See RFC 3548 for the definition of URL-safe
     * base64.
     *
     *```php
     * $random = new \\Phalcon\\Security\\Random();
     *
     * echo $random->base64Safe(); // GD8JojhzSTrqX7Q8J6uug
     *```
     *
     * @link https://www.ietf.org/rfc/rfc3548.txt
     * @throws Exception If secure random number generator is not available or unexpected partial read
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'string',
                'mandatory' => 0,
                'file' => '/app/phalcon/Security/Random.zep',
                'line' => 187,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Security/Random.zep',
            'line' => 187,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Security/Random.zep',
          'line' => 186,
          'last-line' => 229,
          'char' => 19,
        ),
        4 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'bytes',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'len',
              'const' => 0,
              'data-type' => 'int',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'int',
                'value' => '16',
                'file' => '/app/phalcon/Security/Random.zep',
                'line' => 230,
                'char' => 39,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Security/Random.zep',
              'line' => 230,
              'char' => 39,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'declare',
              'data-type' => 'variable',
              'variables' => 
              array (
                0 => 
                array (
                  'variable' => 'handle',
                  'file' => '/app/phalcon/Security/Random.zep',
                  'line' => 232,
                  'char' => 19,
                ),
                1 => 
                array (
                  'variable' => 'ret',
                  'file' => '/app/phalcon/Security/Random.zep',
                  'line' => 232,
                  'char' => 24,
                ),
              ),
              'file' => '/app/phalcon/Security/Random.zep',
              'line' => 234,
              'char' => 10,
            ),
            1 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'less-equal',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'len',
                  'file' => '/app/phalcon/Security/Random.zep',
                  'line' => 234,
                  'char' => 16,
                ),
                'right' => 
                array (
                  'type' => 'int',
                  'value' => '0',
                  'file' => '/app/phalcon/Security/Random.zep',
                  'line' => 234,
                  'char' => 20,
                ),
                'file' => '/app/phalcon/Security/Random.zep',
                'line' => 234,
                'char' => 20,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'let',
                  'assignments' => 
                  array (
                    0 => 
                    array (
                      'assign-type' => 'variable',
                      'operator' => 'assign',
                      'variable' => 'len',
                      'expr' => 
                      array (
                        'type' => 'int',
                        'value' => '16',
                        'file' => '/app/phalcon/Security/Random.zep',
                        'line' => 235,
                        'char' => 25,
                      ),
                      'file' => '/app/phalcon/Security/Random.zep',
                      'line' => 235,
                      'char' => 25,
                    ),
                  ),
                  'file' => '/app/phalcon/Security/Random.zep',
                  'line' => 236,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Security/Random.zep',
              'line' => 238,
              'char' => 10,
            ),
            2 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'fcall',
                'name' => 'function_exists',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'string',
                      'value' => 'random_bytes',
                      'file' => '/app/phalcon/Security/Random.zep',
                      'line' => 238,
                      'char' => 40,
                    ),
                    'file' => '/app/phalcon/Security/Random.zep',
                    'line' => 238,
                    'char' => 40,
                  ),
                ),
                'file' => '/app/phalcon/Security/Random.zep',
                'line' => 238,
                'char' => 42,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'fcall',
                    'name' => 'random_bytes',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'len',
                          'file' => '/app/phalcon/Security/Random.zep',
                          'line' => 239,
                          'char' => 36,
                        ),
                        'file' => '/app/phalcon/Security/Random.zep',
                        'line' => 239,
                        'char' => 36,
                      ),
                    ),
                    'file' => '/app/phalcon/Security/Random.zep',
                    'line' => 239,
                    'char' => 37,
                  ),
                  'file' => '/app/phalcon/Security/Random.zep',
                  'line' => 240,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Security/Random.zep',
              'line' => 242,
              'char' => 10,
            ),
            3 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'fcall',
                'name' => 'function_exists',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'string',
                      'value' => '\\\\Sodium\\\\randombytes_buf',
                      'file' => '/app/phalcon/Security/Random.zep',
                      'line' => 242,
                      'char' => 53,
                    ),
                    'file' => '/app/phalcon/Security/Random.zep',
                    'line' => 242,
                    'char' => 53,
                  ),
                ),
                'file' => '/app/phalcon/Security/Random.zep',
                'line' => 242,
                'char' => 55,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'fcall',
                    'name' => '\\\\Sodium\\\\randombytes_buf',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'len',
                          'file' => '/app/phalcon/Security/Random.zep',
                          'line' => 243,
                          'char' => 49,
                        ),
                        'file' => '/app/phalcon/Security/Random.zep',
                        'line' => 243,
                        'char' => 49,
                      ),
                    ),
                    'file' => '/app/phalcon/Security/Random.zep',
                    'line' => 243,
                    'char' => 50,
                  ),
                  'file' => '/app/phalcon/Security/Random.zep',
                  'line' => 244,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Security/Random.zep',
              'line' => 246,
              'char' => 10,
            ),
            4 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'fcall',
                'name' => 'function_exists',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'string',
                      'value' => 'openssl_random_pseudo_bytes',
                      'file' => '/app/phalcon/Security/Random.zep',
                      'line' => 246,
                      'char' => 55,
                    ),
                    'file' => '/app/phalcon/Security/Random.zep',
                    'line' => 246,
                    'char' => 55,
                  ),
                ),
                'file' => '/app/phalcon/Security/Random.zep',
                'line' => 246,
                'char' => 57,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'fcall',
                    'name' => 'openssl_random_pseudo_bytes',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'len',
                          'file' => '/app/phalcon/Security/Random.zep',
                          'line' => 247,
                          'char' => 51,
                        ),
                        'file' => '/app/phalcon/Security/Random.zep',
                        'line' => 247,
                        'char' => 51,
                      ),
                    ),
                    'file' => '/app/phalcon/Security/Random.zep',
                    'line' => 247,
                    'char' => 52,
                  ),
                  'file' => '/app/phalcon/Security/Random.zep',
                  'line' => 248,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Security/Random.zep',
              'line' => 250,
              'char' => 11,
            ),
            5 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'handle',
                  'expr' => 
                  array (
                    'type' => 'bool',
                    'value' => 'false',
                    'file' => '/app/phalcon/Security/Random.zep',
                    'line' => 250,
                    'char' => 27,
                  ),
                  'file' => '/app/phalcon/Security/Random.zep',
                  'line' => 250,
                  'char' => 27,
                ),
              ),
              'file' => '/app/phalcon/Security/Random.zep',
              'line' => 252,
              'char' => 10,
            ),
            6 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'fcall',
                'name' => 'file_exists',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'string',
                      'value' => '/dev/urandom',
                      'file' => '/app/phalcon/Security/Random.zep',
                      'line' => 252,
                      'char' => 36,
                    ),
                    'file' => '/app/phalcon/Security/Random.zep',
                    'line' => 252,
                    'char' => 36,
                  ),
                ),
                'file' => '/app/phalcon/Security/Random.zep',
                'line' => 252,
                'char' => 38,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'let',
                  'assignments' => 
                  array (
                    0 => 
                    array (
                      'assign-type' => 'variable',
                      'operator' => 'assign',
                      'variable' => 'handle',
                      'expr' => 
                      array (
                        'type' => 'fcall',
                        'name' => 'fopen',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'string',
                              'value' => '/dev/urandom',
                              'file' => '/app/phalcon/Security/Random.zep',
                              'line' => 253,
                              'char' => 44,
                            ),
                            'file' => '/app/phalcon/Security/Random.zep',
                            'line' => 253,
                            'char' => 44,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'string',
                              'value' => 'rb',
                              'file' => '/app/phalcon/Security/Random.zep',
                              'line' => 253,
                              'char' => 48,
                            ),
                            'file' => '/app/phalcon/Security/Random.zep',
                            'line' => 253,
                            'char' => 48,
                          ),
                        ),
                        'file' => '/app/phalcon/Security/Random.zep',
                        'line' => 253,
                        'char' => 49,
                      ),
                      'file' => '/app/phalcon/Security/Random.zep',
                      'line' => 253,
                      'char' => 49,
                    ),
                  ),
                  'file' => '/app/phalcon/Security/Random.zep',
                  'line' => 254,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Security/Random.zep',
              'line' => 256,
              'char' => 10,
            ),
            7 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'unlikely',
                'left' => 
                array (
                  'type' => 'identical',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'handle',
                    'file' => '/app/phalcon/Security/Random.zep',
                    'line' => 256,
                    'char' => 30,
                  ),
                  'right' => 
                  array (
                    'type' => 'bool',
                    'value' => 'false',
                    'file' => '/app/phalcon/Security/Random.zep',
                    'line' => 256,
                    'char' => 38,
                  ),
                  'file' => '/app/phalcon/Security/Random.zep',
                  'line' => 256,
                  'char' => 38,
                ),
                'file' => '/app/phalcon/Security/Random.zep',
                'line' => 256,
                'char' => 38,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'throw',
                  'expr' => 
                  array (
                    'type' => 'new',
                    'class' => 'Exception',
                    'dynamic' => 0,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => 'No random device available',
                          'file' => '/app/phalcon/Security/Random.zep',
                          'line' => 257,
                          'char' => 59,
                        ),
                        'file' => '/app/phalcon/Security/Random.zep',
                        'line' => 257,
                        'char' => 59,
                      ),
                    ),
                    'file' => '/app/phalcon/Security/Random.zep',
                    'line' => 257,
                    'char' => 60,
                  ),
                  'file' => '/app/phalcon/Security/Random.zep',
                  'line' => 258,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Security/Random.zep',
              'line' => 260,
              'char' => 30,
            ),
            8 => 
            array (
              'type' => 'fcall',
              'expr' => 
              array (
                'type' => 'fcall',
                'name' => 'stream_set_read_buffer',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'handle',
                      'file' => '/app/phalcon/Security/Random.zep',
                      'line' => 260,
                      'char' => 38,
                    ),
                    'file' => '/app/phalcon/Security/Random.zep',
                    'line' => 260,
                    'char' => 38,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'int',
                      'value' => '0',
                      'file' => '/app/phalcon/Security/Random.zep',
                      'line' => 260,
                      'char' => 41,
                    ),
                    'file' => '/app/phalcon/Security/Random.zep',
                    'line' => 260,
                    'char' => 41,
                  ),
                ),
                'file' => '/app/phalcon/Security/Random.zep',
                'line' => 260,
                'char' => 42,
              ),
              'file' => '/app/phalcon/Security/Random.zep',
              'line' => 262,
              'char' => 11,
            ),
            9 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'ret',
                  'expr' => 
                  array (
                    'type' => 'fcall',
                    'name' => 'fread',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'handle',
                          'file' => '/app/phalcon/Security/Random.zep',
                          'line' => 262,
                          'char' => 31,
                        ),
                        'file' => '/app/phalcon/Security/Random.zep',
                        'line' => 262,
                        'char' => 31,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'len',
                          'file' => '/app/phalcon/Security/Random.zep',
                          'line' => 262,
                          'char' => 36,
                        ),
                        'file' => '/app/phalcon/Security/Random.zep',
                        'line' => 262,
                        'char' => 36,
                      ),
                    ),
                    'file' => '/app/phalcon/Security/Random.zep',
                    'line' => 262,
                    'char' => 37,
                  ),
                  'file' => '/app/phalcon/Security/Random.zep',
                  'line' => 262,
                  'char' => 37,
                ),
              ),
              'file' => '/app/phalcon/Security/Random.zep',
              'line' => 264,
              'char' => 14,
            ),
            10 => 
            array (
              'type' => 'fcall',
              'expr' => 
              array (
                'type' => 'fcall',
                'name' => 'fclose',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'handle',
                      'file' => '/app/phalcon/Security/Random.zep',
                      'line' => 264,
                      'char' => 22,
                    ),
                    'file' => '/app/phalcon/Security/Random.zep',
                    'line' => 264,
                    'char' => 22,
                  ),
                ),
                'file' => '/app/phalcon/Security/Random.zep',
                'line' => 264,
                'char' => 23,
              ),
              'file' => '/app/phalcon/Security/Random.zep',
              'line' => 266,
              'char' => 10,
            ),
            11 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'unlikely',
                'left' => 
                array (
                  'type' => 'not-equals',
                  'left' => 
                  array (
                    'type' => 'fcall',
                    'name' => 'strlen',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'ret',
                          'file' => '/app/phalcon/Security/Random.zep',
                          'line' => 266,
                          'char' => 31,
                        ),
                        'file' => '/app/phalcon/Security/Random.zep',
                        'line' => 266,
                        'char' => 31,
                      ),
                    ),
                    'file' => '/app/phalcon/Security/Random.zep',
                    'line' => 266,
                    'char' => 34,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'len',
                    'file' => '/app/phalcon/Security/Random.zep',
                    'line' => 266,
                    'char' => 40,
                  ),
                  'file' => '/app/phalcon/Security/Random.zep',
                  'line' => 266,
                  'char' => 40,
                ),
                'file' => '/app/phalcon/Security/Random.zep',
                'line' => 266,
                'char' => 40,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'throw',
                  'expr' => 
                  array (
                    'type' => 'new',
                    'class' => 'Exception',
                    'dynamic' => 0,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => 'Unexpected partial read from random device',
                          'file' => '/app/phalcon/Security/Random.zep',
                          'line' => 269,
                          'char' => 13,
                        ),
                        'file' => '/app/phalcon/Security/Random.zep',
                        'line' => 269,
                        'char' => 13,
                      ),
                    ),
                    'file' => '/app/phalcon/Security/Random.zep',
                    'line' => 269,
                    'char' => 14,
                  ),
                  'file' => '/app/phalcon/Security/Random.zep',
                  'line' => 270,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Security/Random.zep',
              'line' => 272,
              'char' => 14,
            ),
            12 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'ret',
                'file' => '/app/phalcon/Security/Random.zep',
                'line' => 272,
                'char' => 19,
              ),
              'file' => '/app/phalcon/Security/Random.zep',
              'line' => 273,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Generates a random binary string
     *
     * The `Random::bytes` method returns a string and accepts as input an int
     * representing the length in bytes to be returned.
     *
     * If $len is not specified, 16 is assumed. It may be larger in future.
     * The result may contain any byte: "x00" - "xFF".
     *
     *```php
     * $random = new \\Phalcon\\Security\\Random();
     *
     * $bytes = $random->bytes();
     * var_dump(bin2hex($bytes));
     * // Possible output: string(32) "00f6c04b144b41fad6a59111c126e1ee"
     *```
     *
     * @throws Exception If secure random number generator is not available or unexpected partial read
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'string',
                'mandatory' => 0,
                'file' => '/app/phalcon/Security/Random.zep',
                'line' => 231,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Security/Random.zep',
            'line' => 231,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Security/Random.zep',
          'line' => 230,
          'last-line' => 288,
          'char' => 19,
        ),
        5 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'hex',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'len',
              'const' => 0,
              'data-type' => 'int',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Security/Random.zep',
                'line' => 289,
                'char' => 39,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Security/Random.zep',
              'line' => 289,
              'char' => 39,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'fcall',
                'name' => 'array_shift',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'fcall',
                      'name' => 'unpack',
                      'call-type' => 1,
                      'parameters' => 
                      array (
                        0 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'string',
                            'value' => 'H*',
                            'file' => '/app/phalcon/Security/Random.zep',
                            'line' => 293,
                            'char' => 19,
                          ),
                          'file' => '/app/phalcon/Security/Random.zep',
                          'line' => 293,
                          'char' => 19,
                        ),
                        1 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'mcall',
                            'variable' => 
                            array (
                              'type' => 'variable',
                              'value' => 'this',
                              'file' => '/app/phalcon/Security/Random.zep',
                              'line' => 294,
                              'char' => 22,
                            ),
                            'name' => 'bytes',
                            'call-type' => 1,
                            'parameters' => 
                            array (
                              0 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'len',
                                  'file' => '/app/phalcon/Security/Random.zep',
                                  'line' => 294,
                                  'char' => 32,
                                ),
                                'file' => '/app/phalcon/Security/Random.zep',
                                'line' => 294,
                                'char' => 32,
                              ),
                            ),
                            'file' => '/app/phalcon/Security/Random.zep',
                            'line' => 295,
                            'char' => 13,
                          ),
                          'file' => '/app/phalcon/Security/Random.zep',
                          'line' => 295,
                          'char' => 13,
                        ),
                      ),
                      'file' => '/app/phalcon/Security/Random.zep',
                      'line' => 296,
                      'char' => 9,
                    ),
                    'file' => '/app/phalcon/Security/Random.zep',
                    'line' => 296,
                    'char' => 9,
                  ),
                ),
                'file' => '/app/phalcon/Security/Random.zep',
                'line' => 296,
                'char' => 10,
              ),
              'file' => '/app/phalcon/Security/Random.zep',
              'line' => 297,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Generates a random hex string
     *
     * If $len is not specified, 16 is assumed. It may be larger in future.
     * The length of the result string is usually greater of $len.
     *
     *```php
     * $random = new \\Phalcon\\Security\\Random();
     *
     * echo $random->hex(10); // a29f470508d5ccb8e289
     *```
     *
     * @throws Exception If secure random number generator is not available or unexpected partial read
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'string',
                'mandatory' => 0,
                'file' => '/app/phalcon/Security/Random.zep',
                'line' => 290,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Security/Random.zep',
            'line' => 290,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Security/Random.zep',
          'line' => 289,
          'last-line' => 310,
          'char' => 19,
        ),
        6 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'number',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'len',
              'const' => 0,
              'data-type' => 'int',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Security/Random.zep',
              'line' => 311,
              'char' => 35,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'declare',
              'data-type' => 'variable',
              'variables' => 
              array (
                0 => 
                array (
                  'variable' => 'hex',
                  'file' => '/app/phalcon/Security/Random.zep',
                  'line' => 313,
                  'char' => 16,
                ),
                1 => 
                array (
                  'variable' => 'mask',
                  'file' => '/app/phalcon/Security/Random.zep',
                  'line' => 313,
                  'char' => 22,
                ),
                2 => 
                array (
                  'variable' => 'rnd',
                  'file' => '/app/phalcon/Security/Random.zep',
                  'line' => 313,
                  'char' => 27,
                ),
                3 => 
                array (
                  'variable' => 'ret',
                  'file' => '/app/phalcon/Security/Random.zep',
                  'line' => 313,
                  'char' => 32,
                ),
              ),
              'file' => '/app/phalcon/Security/Random.zep',
              'line' => 314,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'declare',
              'data-type' => 'string',
              'variables' => 
              array (
                0 => 
                array (
                  'variable' => 'bin',
                  'expr' => 
                  array (
                    'type' => 'string',
                    'value' => '',
                    'file' => '/app/phalcon/Security/Random.zep',
                    'line' => 314,
                    'char' => 22,
                  ),
                  'file' => '/app/phalcon/Security/Random.zep',
                  'line' => 314,
                  'char' => 22,
                ),
              ),
              'file' => '/app/phalcon/Security/Random.zep',
              'line' => 316,
              'char' => 10,
            ),
            2 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'unlikely',
                'left' => 
                array (
                  'type' => 'less-equal',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'len',
                    'file' => '/app/phalcon/Security/Random.zep',
                    'line' => 316,
                    'char' => 25,
                  ),
                  'right' => 
                  array (
                    'type' => 'int',
                    'value' => '0',
                    'file' => '/app/phalcon/Security/Random.zep',
                    'line' => 316,
                    'char' => 29,
                  ),
                  'file' => '/app/phalcon/Security/Random.zep',
                  'line' => 316,
                  'char' => 29,
                ),
                'file' => '/app/phalcon/Security/Random.zep',
                'line' => 316,
                'char' => 29,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'throw',
                  'expr' => 
                  array (
                    'type' => 'new',
                    'class' => 'Exception',
                    'dynamic' => 0,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => 'Require a positive integer > 0',
                          'file' => '/app/phalcon/Security/Random.zep',
                          'line' => 317,
                          'char' => 63,
                        ),
                        'file' => '/app/phalcon/Security/Random.zep',
                        'line' => 317,
                        'char' => 63,
                      ),
                    ),
                    'file' => '/app/phalcon/Security/Random.zep',
                    'line' => 317,
                    'char' => 64,
                  ),
                  'file' => '/app/phalcon/Security/Random.zep',
                  'line' => 318,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Security/Random.zep',
              'line' => 320,
              'char' => 10,
            ),
            3 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'fcall',
                'name' => 'function_exists',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'string',
                      'value' => 'random_int',
                      'file' => '/app/phalcon/Security/Random.zep',
                      'line' => 320,
                      'char' => 38,
                    ),
                    'file' => '/app/phalcon/Security/Random.zep',
                    'line' => 320,
                    'char' => 38,
                  ),
                ),
                'file' => '/app/phalcon/Security/Random.zep',
                'line' => 320,
                'char' => 40,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'fcall',
                    'name' => 'random_int',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'int',
                          'value' => '0',
                          'file' => '/app/phalcon/Security/Random.zep',
                          'line' => 321,
                          'char' => 32,
                        ),
                        'file' => '/app/phalcon/Security/Random.zep',
                        'line' => 321,
                        'char' => 32,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'len',
                          'file' => '/app/phalcon/Security/Random.zep',
                          'line' => 321,
                          'char' => 37,
                        ),
                        'file' => '/app/phalcon/Security/Random.zep',
                        'line' => 321,
                        'char' => 37,
                      ),
                    ),
                    'file' => '/app/phalcon/Security/Random.zep',
                    'line' => 321,
                    'char' => 38,
                  ),
                  'file' => '/app/phalcon/Security/Random.zep',
                  'line' => 322,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Security/Random.zep',
              'line' => 324,
              'char' => 10,
            ),
            4 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'fcall',
                'name' => 'function_exists',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'string',
                      'value' => '\\\\Sodium\\\\randombytes_uniform',
                      'file' => '/app/phalcon/Security/Random.zep',
                      'line' => 324,
                      'char' => 57,
                    ),
                    'file' => '/app/phalcon/Security/Random.zep',
                    'line' => 324,
                    'char' => 57,
                  ),
                ),
                'file' => '/app/phalcon/Security/Random.zep',
                'line' => 324,
                'char' => 59,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'add',
                    'left' => 
                    array (
                      'type' => 'fcall',
                      'name' => '\\\\Sodium\\\\randombytes_uniform',
                      'call-type' => 1,
                      'parameters' => 
                      array (
                        0 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'variable',
                            'value' => 'len',
                            'file' => '/app/phalcon/Security/Random.zep',
                            'line' => 329,
                            'char' => 53,
                          ),
                          'file' => '/app/phalcon/Security/Random.zep',
                          'line' => 329,
                          'char' => 53,
                        ),
                      ),
                      'file' => '/app/phalcon/Security/Random.zep',
                      'line' => 329,
                      'char' => 55,
                    ),
                    'right' => 
                    array (
                      'type' => 'int',
                      'value' => '1',
                      'file' => '/app/phalcon/Security/Random.zep',
                      'line' => 329,
                      'char' => 58,
                    ),
                    'file' => '/app/phalcon/Security/Random.zep',
                    'line' => 329,
                    'char' => 58,
                  ),
                  'file' => '/app/phalcon/Security/Random.zep',
                  'line' => 330,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Security/Random.zep',
              'line' => 332,
              'char' => 11,
            ),
            5 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'hex',
                  'expr' => 
                  array (
                    'type' => 'fcall',
                    'name' => 'dechex',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'len',
                          'file' => '/app/phalcon/Security/Random.zep',
                          'line' => 332,
                          'char' => 29,
                        ),
                        'file' => '/app/phalcon/Security/Random.zep',
                        'line' => 332,
                        'char' => 29,
                      ),
                    ),
                    'file' => '/app/phalcon/Security/Random.zep',
                    'line' => 332,
                    'char' => 30,
                  ),
                  'file' => '/app/phalcon/Security/Random.zep',
                  'line' => 332,
                  'char' => 30,
                ),
              ),
              'file' => '/app/phalcon/Security/Random.zep',
              'line' => 334,
              'char' => 10,
            ),
            6 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'equals',
                'left' => 
                array (
                  'type' => 'list',
                  'left' => 
                  array (
                    'type' => 'bitwise_and',
                    'left' => 
                    array (
                      'type' => 'fcall',
                      'name' => 'strlen',
                      'call-type' => 1,
                      'parameters' => 
                      array (
                        0 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'variable',
                            'value' => 'hex',
                            'file' => '/app/phalcon/Security/Random.zep',
                            'line' => 334,
                            'char' => 23,
                          ),
                          'file' => '/app/phalcon/Security/Random.zep',
                          'line' => 334,
                          'char' => 23,
                        ),
                      ),
                      'file' => '/app/phalcon/Security/Random.zep',
                      'line' => 334,
                      'char' => 25,
                    ),
                    'right' => 
                    array (
                      'type' => 'int',
                      'value' => '1',
                      'file' => '/app/phalcon/Security/Random.zep',
                      'line' => 334,
                      'char' => 28,
                    ),
                    'file' => '/app/phalcon/Security/Random.zep',
                    'line' => 334,
                    'char' => 28,
                  ),
                  'file' => '/app/phalcon/Security/Random.zep',
                  'line' => 334,
                  'char' => 31,
                ),
                'right' => 
                array (
                  'type' => 'int',
                  'value' => '1',
                  'file' => '/app/phalcon/Security/Random.zep',
                  'line' => 334,
                  'char' => 35,
                ),
                'file' => '/app/phalcon/Security/Random.zep',
                'line' => 334,
                'char' => 35,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'let',
                  'assignments' => 
                  array (
                    0 => 
                    array (
                      'assign-type' => 'variable',
                      'operator' => 'assign',
                      'variable' => 'hex',
                      'expr' => 
                      array (
                        'type' => 'concat',
                        'left' => 
                        array (
                          'type' => 'string',
                          'value' => '0',
                          'file' => '/app/phalcon/Security/Random.zep',
                          'line' => 335,
                          'char' => 25,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'hex',
                          'file' => '/app/phalcon/Security/Random.zep',
                          'line' => 335,
                          'char' => 30,
                        ),
                        'file' => '/app/phalcon/Security/Random.zep',
                        'line' => 335,
                        'char' => 30,
                      ),
                      'file' => '/app/phalcon/Security/Random.zep',
                      'line' => 335,
                      'char' => 30,
                    ),
                  ),
                  'file' => '/app/phalcon/Security/Random.zep',
                  'line' => 336,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Security/Random.zep',
              'line' => 338,
              'char' => 11,
            ),
            7 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'concat-assign',
                  'variable' => 'bin',
                  'expr' => 
                  array (
                    'type' => 'fcall',
                    'name' => 'pack',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => 'H*',
                          'file' => '/app/phalcon/Security/Random.zep',
                          'line' => 338,
                          'char' => 26,
                        ),
                        'file' => '/app/phalcon/Security/Random.zep',
                        'line' => 338,
                        'char' => 26,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'hex',
                          'file' => '/app/phalcon/Security/Random.zep',
                          'line' => 338,
                          'char' => 31,
                        ),
                        'file' => '/app/phalcon/Security/Random.zep',
                        'line' => 338,
                        'char' => 31,
                      ),
                    ),
                    'file' => '/app/phalcon/Security/Random.zep',
                    'line' => 338,
                    'char' => 32,
                  ),
                  'file' => '/app/phalcon/Security/Random.zep',
                  'line' => 338,
                  'char' => 32,
                ),
              ),
              'file' => '/app/phalcon/Security/Random.zep',
              'line' => 340,
              'char' => 11,
            ),
            8 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'mask',
                  'expr' => 
                  array (
                    'type' => 'fcall',
                    'name' => 'ord',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'array-access',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'bin',
                            'file' => '/app/phalcon/Security/Random.zep',
                            'line' => 340,
                            'char' => 27,
                          ),
                          'right' => 
                          array (
                            'type' => 'int',
                            'value' => '0',
                            'file' => '/app/phalcon/Security/Random.zep',
                            'line' => 340,
                            'char' => 29,
                          ),
                          'file' => '/app/phalcon/Security/Random.zep',
                          'line' => 340,
                          'char' => 30,
                        ),
                        'file' => '/app/phalcon/Security/Random.zep',
                        'line' => 340,
                        'char' => 30,
                      ),
                    ),
                    'file' => '/app/phalcon/Security/Random.zep',
                    'line' => 340,
                    'char' => 31,
                  ),
                  'file' => '/app/phalcon/Security/Random.zep',
                  'line' => 340,
                  'char' => 31,
                ),
              ),
              'file' => '/app/phalcon/Security/Random.zep',
              'line' => 341,
              'char' => 11,
            ),
            9 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'mask',
                  'expr' => 
                  array (
                    'type' => 'bitwise_or',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'mask',
                      'file' => '/app/phalcon/Security/Random.zep',
                      'line' => 341,
                      'char' => 25,
                    ),
                    'right' => 
                    array (
                      'type' => 'list',
                      'left' => 
                      array (
                        'type' => 'bitwise_shiftright',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'mask',
                          'file' => '/app/phalcon/Security/Random.zep',
                          'line' => 341,
                          'char' => 34,
                        ),
                        'right' => 
                        array (
                          'type' => 'int',
                          'value' => '1',
                          'file' => '/app/phalcon/Security/Random.zep',
                          'line' => 341,
                          'char' => 37,
                        ),
                        'file' => '/app/phalcon/Security/Random.zep',
                        'line' => 341,
                        'char' => 37,
                      ),
                      'file' => '/app/phalcon/Security/Random.zep',
                      'line' => 341,
                      'char' => 38,
                    ),
                    'file' => '/app/phalcon/Security/Random.zep',
                    'line' => 341,
                    'char' => 38,
                  ),
                  'file' => '/app/phalcon/Security/Random.zep',
                  'line' => 341,
                  'char' => 38,
                ),
              ),
              'file' => '/app/phalcon/Security/Random.zep',
              'line' => 342,
              'char' => 11,
            ),
            10 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'mask',
                  'expr' => 
                  array (
                    'type' => 'bitwise_or',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'mask',
                      'file' => '/app/phalcon/Security/Random.zep',
                      'line' => 342,
                      'char' => 25,
                    ),
                    'right' => 
                    array (
                      'type' => 'list',
                      'left' => 
                      array (
                        'type' => 'bitwise_shiftright',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'mask',
                          'file' => '/app/phalcon/Security/Random.zep',
                          'line' => 342,
                          'char' => 34,
                        ),
                        'right' => 
                        array (
                          'type' => 'int',
                          'value' => '2',
                          'file' => '/app/phalcon/Security/Random.zep',
                          'line' => 342,
                          'char' => 37,
                        ),
                        'file' => '/app/phalcon/Security/Random.zep',
                        'line' => 342,
                        'char' => 37,
                      ),
                      'file' => '/app/phalcon/Security/Random.zep',
                      'line' => 342,
                      'char' => 38,
                    ),
                    'file' => '/app/phalcon/Security/Random.zep',
                    'line' => 342,
                    'char' => 38,
                  ),
                  'file' => '/app/phalcon/Security/Random.zep',
                  'line' => 342,
                  'char' => 38,
                ),
              ),
              'file' => '/app/phalcon/Security/Random.zep',
              'line' => 343,
              'char' => 11,
            ),
            11 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'mask',
                  'expr' => 
                  array (
                    'type' => 'bitwise_or',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'mask',
                      'file' => '/app/phalcon/Security/Random.zep',
                      'line' => 343,
                      'char' => 25,
                    ),
                    'right' => 
                    array (
                      'type' => 'list',
                      'left' => 
                      array (
                        'type' => 'bitwise_shiftright',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'mask',
                          'file' => '/app/phalcon/Security/Random.zep',
                          'line' => 343,
                          'char' => 34,
                        ),
                        'right' => 
                        array (
                          'type' => 'int',
                          'value' => '4',
                          'file' => '/app/phalcon/Security/Random.zep',
                          'line' => 343,
                          'char' => 37,
                        ),
                        'file' => '/app/phalcon/Security/Random.zep',
                        'line' => 343,
                        'char' => 37,
                      ),
                      'file' => '/app/phalcon/Security/Random.zep',
                      'line' => 343,
                      'char' => 38,
                    ),
                    'file' => '/app/phalcon/Security/Random.zep',
                    'line' => 343,
                    'char' => 38,
                  ),
                  'file' => '/app/phalcon/Security/Random.zep',
                  'line' => 343,
                  'char' => 38,
                ),
              ),
              'file' => '/app/phalcon/Security/Random.zep',
              'line' => 345,
              'char' => 10,
            ),
            12 => 
            array (
              'type' => 'do-while',
              'expr' => 
              array (
                'type' => 'less',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'bin',
                  'file' => '/app/phalcon/Security/Random.zep',
                  'line' => 356,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'rnd',
                  'file' => '/app/phalcon/Security/Random.zep',
                  'line' => 356,
                  'char' => 26,
                ),
                'file' => '/app/phalcon/Security/Random.zep',
                'line' => 356,
                'char' => 26,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'let',
                  'assignments' => 
                  array (
                    0 => 
                    array (
                      'assign-type' => 'variable',
                      'operator' => 'assign',
                      'variable' => 'rnd',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Security/Random.zep',
                          'line' => 346,
                          'char' => 28,
                        ),
                        'name' => 'bytes',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'fcall',
                              'name' => 'strlen',
                              'call-type' => 1,
                              'parameters' => 
                              array (
                                0 => 
                                array (
                                  'parameter' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'bin',
                                    'file' => '/app/phalcon/Security/Random.zep',
                                    'line' => 346,
                                    'char' => 45,
                                  ),
                                  'file' => '/app/phalcon/Security/Random.zep',
                                  'line' => 346,
                                  'char' => 45,
                                ),
                              ),
                              'file' => '/app/phalcon/Security/Random.zep',
                              'line' => 346,
                              'char' => 46,
                            ),
                            'file' => '/app/phalcon/Security/Random.zep',
                            'line' => 346,
                            'char' => 46,
                          ),
                        ),
                        'file' => '/app/phalcon/Security/Random.zep',
                        'line' => 346,
                        'char' => 47,
                      ),
                      'file' => '/app/phalcon/Security/Random.zep',
                      'line' => 346,
                      'char' => 47,
                    ),
                  ),
                  'file' => '/app/phalcon/Security/Random.zep',
                  'line' => 348,
                  'char' => 15,
                ),
                1 => 
                array (
                  'type' => 'let',
                  'assignments' => 
                  array (
                    0 => 
                    array (
                      'assign-type' => 'variable',
                      'operator' => 'assign',
                      'variable' => 'rnd',
                      'expr' => 
                      array (
                        'type' => 'fcall',
                        'name' => 'substr_replace',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'rnd',
                              'file' => '/app/phalcon/Security/Random.zep',
                              'line' => 349,
                              'char' => 20,
                            ),
                            'file' => '/app/phalcon/Security/Random.zep',
                            'line' => 349,
                            'char' => 20,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'fcall',
                              'name' => 'chr',
                              'call-type' => 1,
                              'parameters' => 
                              array (
                                0 => 
                                array (
                                  'parameter' => 
                                  array (
                                    'type' => 'bitwise_and',
                                    'left' => 
                                    array (
                                      'type' => 'fcall',
                                      'name' => 'ord',
                                      'call-type' => 1,
                                      'parameters' => 
                                      array (
                                        0 => 
                                        array (
                                          'parameter' => 
                                          array (
                                            'type' => 'fcall',
                                            'name' => 'substr',
                                            'call-type' => 1,
                                            'parameters' => 
                                            array (
                                              0 => 
                                              array (
                                                'parameter' => 
                                                array (
                                                  'type' => 'variable',
                                                  'value' => 'rnd',
                                                  'file' => '/app/phalcon/Security/Random.zep',
                                                  'line' => 351,
                                                  'char' => 35,
                                                ),
                                                'file' => '/app/phalcon/Security/Random.zep',
                                                'line' => 351,
                                                'char' => 35,
                                              ),
                                              1 => 
                                              array (
                                                'parameter' => 
                                                array (
                                                  'type' => 'int',
                                                  'value' => '0',
                                                  'file' => '/app/phalcon/Security/Random.zep',
                                                  'line' => 351,
                                                  'char' => 38,
                                                ),
                                                'file' => '/app/phalcon/Security/Random.zep',
                                                'line' => 351,
                                                'char' => 38,
                                              ),
                                              2 => 
                                              array (
                                                'parameter' => 
                                                array (
                                                  'type' => 'int',
                                                  'value' => '1',
                                                  'file' => '/app/phalcon/Security/Random.zep',
                                                  'line' => 351,
                                                  'char' => 41,
                                                ),
                                                'file' => '/app/phalcon/Security/Random.zep',
                                                'line' => 351,
                                                'char' => 41,
                                              ),
                                            ),
                                            'file' => '/app/phalcon/Security/Random.zep',
                                            'line' => 351,
                                            'char' => 42,
                                          ),
                                          'file' => '/app/phalcon/Security/Random.zep',
                                          'line' => 351,
                                          'char' => 42,
                                        ),
                                      ),
                                      'file' => '/app/phalcon/Security/Random.zep',
                                      'line' => 351,
                                      'char' => 44,
                                    ),
                                    'right' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'mask',
                                      'file' => '/app/phalcon/Security/Random.zep',
                                      'line' => 352,
                                      'char' => 17,
                                    ),
                                    'file' => '/app/phalcon/Security/Random.zep',
                                    'line' => 352,
                                    'char' => 17,
                                  ),
                                  'file' => '/app/phalcon/Security/Random.zep',
                                  'line' => 352,
                                  'char' => 17,
                                ),
                              ),
                              'file' => '/app/phalcon/Security/Random.zep',
                              'line' => 352,
                              'char' => 18,
                            ),
                            'file' => '/app/phalcon/Security/Random.zep',
                            'line' => 352,
                            'char' => 18,
                          ),
                          2 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'int',
                              'value' => '0',
                              'file' => '/app/phalcon/Security/Random.zep',
                              'line' => 353,
                              'char' => 18,
                            ),
                            'file' => '/app/phalcon/Security/Random.zep',
                            'line' => 353,
                            'char' => 18,
                          ),
                          3 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'int',
                              'value' => '1',
                              'file' => '/app/phalcon/Security/Random.zep',
                              'line' => 355,
                              'char' => 13,
                            ),
                            'file' => '/app/phalcon/Security/Random.zep',
                            'line' => 355,
                            'char' => 13,
                          ),
                        ),
                        'file' => '/app/phalcon/Security/Random.zep',
                        'line' => 355,
                        'char' => 14,
                      ),
                      'file' => '/app/phalcon/Security/Random.zep',
                      'line' => 355,
                      'char' => 14,
                    ),
                  ),
                  'file' => '/app/phalcon/Security/Random.zep',
                  'line' => 356,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Security/Random.zep',
              'line' => 358,
              'char' => 11,
            ),
            13 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'ret',
                  'expr' => 
                  array (
                    'type' => 'fcall',
                    'name' => 'unpack',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => 'H*',
                          'file' => '/app/phalcon/Security/Random.zep',
                          'line' => 358,
                          'char' => 28,
                        ),
                        'file' => '/app/phalcon/Security/Random.zep',
                        'line' => 358,
                        'char' => 28,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'rnd',
                          'file' => '/app/phalcon/Security/Random.zep',
                          'line' => 358,
                          'char' => 33,
                        ),
                        'file' => '/app/phalcon/Security/Random.zep',
                        'line' => 358,
                        'char' => 33,
                      ),
                    ),
                    'file' => '/app/phalcon/Security/Random.zep',
                    'line' => 358,
                    'char' => 34,
                  ),
                  'file' => '/app/phalcon/Security/Random.zep',
                  'line' => 358,
                  'char' => 34,
                ),
              ),
              'file' => '/app/phalcon/Security/Random.zep',
              'line' => 360,
              'char' => 14,
            ),
            14 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'fcall',
                'name' => 'hexdec',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'fcall',
                      'name' => 'array_shift',
                      'call-type' => 1,
                      'parameters' => 
                      array (
                        0 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'variable',
                            'value' => 'ret',
                            'file' => '/app/phalcon/Security/Random.zep',
                            'line' => 361,
                            'char' => 28,
                          ),
                          'file' => '/app/phalcon/Security/Random.zep',
                          'line' => 361,
                          'char' => 28,
                        ),
                      ),
                      'file' => '/app/phalcon/Security/Random.zep',
                      'line' => 362,
                      'char' => 9,
                    ),
                    'file' => '/app/phalcon/Security/Random.zep',
                    'line' => 362,
                    'char' => 9,
                  ),
                ),
                'file' => '/app/phalcon/Security/Random.zep',
                'line' => 362,
                'char' => 10,
              ),
              'file' => '/app/phalcon/Security/Random.zep',
              'line' => 363,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Generates a random number between 0 and $len
     *
     * Returns an integer: 0 <= result <= $len.
     *
     *```php
     * $random = new \\Phalcon\\Security\\Random();
     *
     * echo $random->number(16); // 8
     *```
     * @throws Exception If secure random number generator is not available, unexpected partial read or $len <= 0
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'int',
                'mandatory' => 0,
                'file' => '/app/phalcon/Security/Random.zep',
                'line' => 312,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Security/Random.zep',
            'line' => 312,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Security/Random.zep',
          'line' => 311,
          'last-line' => 386,
          'char' => 19,
        ),
        7 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'uuid',
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'declare',
              'data-type' => 'variable',
              'variables' => 
              array (
                0 => 
                array (
                  'variable' => 'ary',
                  'file' => '/app/phalcon/Security/Random.zep',
                  'line' => 389,
                  'char' => 16,
                ),
              ),
              'file' => '/app/phalcon/Security/Random.zep',
              'line' => 391,
              'char' => 11,
            ),
            1 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'ary',
                  'expr' => 
                  array (
                    'type' => 'fcall',
                    'name' => 'array_values',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'fcall',
                          'name' => 'unpack',
                          'call-type' => 1,
                          'parameters' => 
                          array (
                            0 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'string',
                                'value' => 'N1a/n1b/n1c/n1d/n1e/N1f',
                                'file' => '/app/phalcon/Security/Random.zep',
                                'line' => 393,
                                'char' => 40,
                              ),
                              'file' => '/app/phalcon/Security/Random.zep',
                              'line' => 393,
                              'char' => 40,
                            ),
                            1 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'mcall',
                                'variable' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'this',
                                  'file' => '/app/phalcon/Security/Random.zep',
                                  'line' => 394,
                                  'char' => 22,
                                ),
                                'name' => 'bytes',
                                'call-type' => 1,
                                'parameters' => 
                                array (
                                  0 => 
                                  array (
                                    'parameter' => 
                                    array (
                                      'type' => 'int',
                                      'value' => '16',
                                      'file' => '/app/phalcon/Security/Random.zep',
                                      'line' => 394,
                                      'char' => 31,
                                    ),
                                    'file' => '/app/phalcon/Security/Random.zep',
                                    'line' => 394,
                                    'char' => 31,
                                  ),
                                ),
                                'file' => '/app/phalcon/Security/Random.zep',
                                'line' => 395,
                                'char' => 13,
                              ),
                              'file' => '/app/phalcon/Security/Random.zep',
                              'line' => 395,
                              'char' => 13,
                            ),
                          ),
                          'file' => '/app/phalcon/Security/Random.zep',
                          'line' => 396,
                          'char' => 9,
                        ),
                        'file' => '/app/phalcon/Security/Random.zep',
                        'line' => 396,
                        'char' => 9,
                      ),
                    ),
                    'file' => '/app/phalcon/Security/Random.zep',
                    'line' => 396,
                    'char' => 10,
                  ),
                  'file' => '/app/phalcon/Security/Random.zep',
                  'line' => 396,
                  'char' => 10,
                ),
              ),
              'file' => '/app/phalcon/Security/Random.zep',
              'line' => 398,
              'char' => 11,
            ),
            2 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'array-index',
                  'operator' => 'assign',
                  'variable' => 'ary',
                  'index-expr' => 
                  array (
                    0 => 
                    array (
                      'type' => 'int',
                      'value' => '2',
                      'file' => '/app/phalcon/Security/Random.zep',
                      'line' => 398,
                      'char' => 18,
                    ),
                  ),
                  'expr' => 
                  array (
                    'type' => 'bitwise_or',
                    'left' => 
                    array (
                      'type' => 'list',
                      'left' => 
                      array (
                        'type' => 'bitwise_and',
                        'left' => 
                        array (
                          'type' => 'array-access',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'ary',
                            'file' => '/app/phalcon/Security/Random.zep',
                            'line' => 398,
                            'char' => 26,
                          ),
                          'right' => 
                          array (
                            'type' => 'int',
                            'value' => '2',
                            'file' => '/app/phalcon/Security/Random.zep',
                            'line' => 398,
                            'char' => 28,
                          ),
                          'file' => '/app/phalcon/Security/Random.zep',
                          'line' => 398,
                          'char' => 30,
                        ),
                        'right' => 
                        array (
                          'type' => 'int',
                          'value' => '0x0fff',
                          'file' => '/app/phalcon/Security/Random.zep',
                          'line' => 398,
                          'char' => 38,
                        ),
                        'file' => '/app/phalcon/Security/Random.zep',
                        'line' => 398,
                        'char' => 38,
                      ),
                      'file' => '/app/phalcon/Security/Random.zep',
                      'line' => 398,
                      'char' => 40,
                    ),
                    'right' => 
                    array (
                      'type' => 'int',
                      'value' => '0x4000',
                      'file' => '/app/phalcon/Security/Random.zep',
                      'line' => 398,
                      'char' => 48,
                    ),
                    'file' => '/app/phalcon/Security/Random.zep',
                    'line' => 398,
                    'char' => 48,
                  ),
                  'file' => '/app/phalcon/Security/Random.zep',
                  'line' => 398,
                  'char' => 48,
                ),
                1 => 
                array (
                  'assign-type' => 'array-index',
                  'operator' => 'assign',
                  'variable' => 'ary',
                  'index-expr' => 
                  array (
                    0 => 
                    array (
                      'type' => 'int',
                      'value' => '3',
                      'file' => '/app/phalcon/Security/Random.zep',
                      'line' => 399,
                      'char' => 18,
                    ),
                  ),
                  'expr' => 
                  array (
                    'type' => 'bitwise_or',
                    'left' => 
                    array (
                      'type' => 'list',
                      'left' => 
                      array (
                        'type' => 'bitwise_and',
                        'left' => 
                        array (
                          'type' => 'array-access',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'ary',
                            'file' => '/app/phalcon/Security/Random.zep',
                            'line' => 399,
                            'char' => 26,
                          ),
                          'right' => 
                          array (
                            'type' => 'int',
                            'value' => '3',
                            'file' => '/app/phalcon/Security/Random.zep',
                            'line' => 399,
                            'char' => 28,
                          ),
                          'file' => '/app/phalcon/Security/Random.zep',
                          'line' => 399,
                          'char' => 30,
                        ),
                        'right' => 
                        array (
                          'type' => 'int',
                          'value' => '0x3fff',
                          'file' => '/app/phalcon/Security/Random.zep',
                          'line' => 399,
                          'char' => 38,
                        ),
                        'file' => '/app/phalcon/Security/Random.zep',
                        'line' => 399,
                        'char' => 38,
                      ),
                      'file' => '/app/phalcon/Security/Random.zep',
                      'line' => 399,
                      'char' => 40,
                    ),
                    'right' => 
                    array (
                      'type' => 'int',
                      'value' => '0x8000',
                      'file' => '/app/phalcon/Security/Random.zep',
                      'line' => 399,
                      'char' => 48,
                    ),
                    'file' => '/app/phalcon/Security/Random.zep',
                    'line' => 399,
                    'char' => 48,
                  ),
                  'file' => '/app/phalcon/Security/Random.zep',
                  'line' => 399,
                  'char' => 48,
                ),
              ),
              'file' => '/app/phalcon/Security/Random.zep',
              'line' => 401,
              'char' => 21,
            ),
            3 => 
            array (
              'type' => 'fcall',
              'expr' => 
              array (
                'type' => 'fcall',
                'name' => 'array_unshift',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'ary',
                      'file' => '/app/phalcon/Security/Random.zep',
                      'line' => 402,
                      'char' => 16,
                    ),
                    'file' => '/app/phalcon/Security/Random.zep',
                    'line' => 402,
                    'char' => 16,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'string',
                      'value' => '%08x-%04x-%04x-%04x-%04x%08x',
                      'file' => '/app/phalcon/Security/Random.zep',
                      'line' => 404,
                      'char' => 9,
                    ),
                    'file' => '/app/phalcon/Security/Random.zep',
                    'line' => 404,
                    'char' => 9,
                  ),
                ),
                'file' => '/app/phalcon/Security/Random.zep',
                'line' => 404,
                'char' => 10,
              ),
              'file' => '/app/phalcon/Security/Random.zep',
              'line' => 406,
              'char' => 14,
            ),
            4 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'fcall',
                'name' => 'call_user_func_array',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'string',
                      'value' => 'sprintf',
                      'file' => '/app/phalcon/Security/Random.zep',
                      'line' => 406,
                      'char' => 44,
                    ),
                    'file' => '/app/phalcon/Security/Random.zep',
                    'line' => 406,
                    'char' => 44,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'ary',
                      'file' => '/app/phalcon/Security/Random.zep',
                      'line' => 406,
                      'char' => 49,
                    ),
                    'file' => '/app/phalcon/Security/Random.zep',
                    'line' => 406,
                    'char' => 49,
                  ),
                ),
                'file' => '/app/phalcon/Security/Random.zep',
                'line' => 406,
                'char' => 50,
              ),
              'file' => '/app/phalcon/Security/Random.zep',
              'line' => 407,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Generates a v4 random UUID (Universally Unique IDentifier)
     *
     * The version 4 UUID is purely random (except the version). It doesn\'t
     * contain meaningful information such as MAC address, time, etc. See RFC
     * 4122 for details of UUID.
     *
     * This algorithm sets the version number (4 bits) as well as two reserved
     * bits. All other bits (the remaining 122 bits) are set using a random or
     * pseudorandom data source. Version 4 UUIDs have the form
     * xxxxxxxx-xxxx-4xxx-yxxx-xxxxxxxxxxxx where x is any hexadecimal digit and
     * y is one of 8, 9, A, or B (e.g., f47ac10b-58cc-4372-a567-0e02b2c3d479).
     *
     *```php
     * $random = new \\Phalcon\\Security\\Random();
     *
     * echo $random->uuid(); // 1378c906-64bb-4f81-a8d6-4ae1bfcdec22
     *```
     *
     * @link https://www.ietf.org/rfc/rfc4122.txt
     * @throws Exception If secure random number generator is not available or unexpected partial read
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'string',
                'mandatory' => 0,
                'file' => '/app/phalcon/Security/Random.zep',
                'line' => 388,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Security/Random.zep',
            'line' => 388,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Security/Random.zep',
          'line' => 387,
          'last-line' => 417,
          'char' => 19,
        ),
        8 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'method',
          'name' => 'base',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'alphabet',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Security/Random.zep',
              'line' => 418,
              'char' => 44,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'base',
              'const' => 0,
              'data-type' => 'int',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Security/Random.zep',
              'line' => 418,
              'char' => 54,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'n',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Security/Random.zep',
                'line' => 418,
                'char' => 64,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Security/Random.zep',
              'line' => 418,
              'char' => 64,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'declare',
              'data-type' => 'variable',
              'variables' => 
              array (
                0 => 
                array (
                  'variable' => 'bytes',
                  'file' => '/app/phalcon/Security/Random.zep',
                  'line' => 420,
                  'char' => 18,
                ),
                1 => 
                array (
                  'variable' => 'idx',
                  'file' => '/app/phalcon/Security/Random.zep',
                  'line' => 420,
                  'char' => 23,
                ),
              ),
              'file' => '/app/phalcon/Security/Random.zep',
              'line' => 421,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'declare',
              'data-type' => 'string',
              'variables' => 
              array (
                0 => 
                array (
                  'variable' => 'byteString',
                  'expr' => 
                  array (
                    'type' => 'string',
                    'value' => '',
                    'file' => '/app/phalcon/Security/Random.zep',
                    'line' => 421,
                    'char' => 29,
                  ),
                  'file' => '/app/phalcon/Security/Random.zep',
                  'line' => 421,
                  'char' => 29,
                ),
              ),
              'file' => '/app/phalcon/Security/Random.zep',
              'line' => 423,
              'char' => 11,
            ),
            2 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'bytes',
                  'expr' => 
                  array (
                    'type' => 'fcall',
                    'name' => 'unpack',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => 'C*',
                          'file' => '/app/phalcon/Security/Random.zep',
                          'line' => 424,
                          'char' => 15,
                        ),
                        'file' => '/app/phalcon/Security/Random.zep',
                        'line' => 424,
                        'char' => 15,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'mcall',
                          'variable' => 
                          array (
                            'type' => 'variable',
                            'value' => 'this',
                            'file' => '/app/phalcon/Security/Random.zep',
                            'line' => 425,
                            'char' => 18,
                          ),
                          'name' => 'bytes',
                          'call-type' => 1,
                          'parameters' => 
                          array (
                            0 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'variable',
                                'value' => 'n',
                                'file' => '/app/phalcon/Security/Random.zep',
                                'line' => 425,
                                'char' => 26,
                              ),
                              'file' => '/app/phalcon/Security/Random.zep',
                              'line' => 425,
                              'char' => 26,
                            ),
                          ),
                          'file' => '/app/phalcon/Security/Random.zep',
                          'line' => 426,
                          'char' => 9,
                        ),
                        'file' => '/app/phalcon/Security/Random.zep',
                        'line' => 426,
                        'char' => 9,
                      ),
                    ),
                    'file' => '/app/phalcon/Security/Random.zep',
                    'line' => 426,
                    'char' => 10,
                  ),
                  'file' => '/app/phalcon/Security/Random.zep',
                  'line' => 426,
                  'char' => 10,
                ),
              ),
              'file' => '/app/phalcon/Security/Random.zep',
              'line' => 428,
              'char' => 11,
            ),
            3 => 
            array (
              'type' => 'for',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'bytes',
                'file' => '/app/phalcon/Security/Random.zep',
                'line' => 428,
                'char' => 26,
              ),
              'value' => 'idx',
              'reverse' => 0,
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'let',
                  'assignments' => 
                  array (
                    0 => 
                    array (
                      'assign-type' => 'variable',
                      'operator' => 'assign',
                      'variable' => 'idx',
                      'expr' => 
                      array (
                        'type' => 'mod',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'idx',
                          'file' => '/app/phalcon/Security/Random.zep',
                          'line' => 429,
                          'char' => 27,
                        ),
                        'right' => 
                        array (
                          'type' => 'int',
                          'value' => '64',
                          'file' => '/app/phalcon/Security/Random.zep',
                          'line' => 429,
                          'char' => 31,
                        ),
                        'file' => '/app/phalcon/Security/Random.zep',
                        'line' => 429,
                        'char' => 31,
                      ),
                      'file' => '/app/phalcon/Security/Random.zep',
                      'line' => 429,
                      'char' => 31,
                    ),
                  ),
                  'file' => '/app/phalcon/Security/Random.zep',
                  'line' => 431,
                  'char' => 14,
                ),
                1 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'greater-equal',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'idx',
                      'file' => '/app/phalcon/Security/Random.zep',
                      'line' => 431,
                      'char' => 20,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'base',
                      'file' => '/app/phalcon/Security/Random.zep',
                      'line' => 431,
                      'char' => 27,
                    ),
                    'file' => '/app/phalcon/Security/Random.zep',
                    'line' => 431,
                    'char' => 27,
                  ),
                  'statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'let',
                      'assignments' => 
                      array (
                        0 => 
                        array (
                          'assign-type' => 'variable',
                          'operator' => 'assign',
                          'variable' => 'idx',
                          'expr' => 
                          array (
                            'type' => 'mcall',
                            'variable' => 
                            array (
                              'type' => 'variable',
                              'value' => 'this',
                              'file' => '/app/phalcon/Security/Random.zep',
                              'line' => 432,
                              'char' => 32,
                            ),
                            'name' => 'number',
                            'call-type' => 1,
                            'parameters' => 
                            array (
                              0 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'sub',
                                  'left' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'base',
                                    'file' => '/app/phalcon/Security/Random.zep',
                                    'line' => 432,
                                    'char' => 45,
                                  ),
                                  'right' => 
                                  array (
                                    'type' => 'int',
                                    'value' => '1',
                                    'file' => '/app/phalcon/Security/Random.zep',
                                    'line' => 432,
                                    'char' => 48,
                                  ),
                                  'file' => '/app/phalcon/Security/Random.zep',
                                  'line' => 432,
                                  'char' => 48,
                                ),
                                'file' => '/app/phalcon/Security/Random.zep',
                                'line' => 432,
                                'char' => 48,
                              ),
                            ),
                            'file' => '/app/phalcon/Security/Random.zep',
                            'line' => 432,
                            'char' => 49,
                          ),
                          'file' => '/app/phalcon/Security/Random.zep',
                          'line' => 432,
                          'char' => 49,
                        ),
                      ),
                      'file' => '/app/phalcon/Security/Random.zep',
                      'line' => 433,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Security/Random.zep',
                  'line' => 435,
                  'char' => 15,
                ),
                2 => 
                array (
                  'type' => 'let',
                  'assignments' => 
                  array (
                    0 => 
                    array (
                      'assign-type' => 'variable',
                      'operator' => 'concat-assign',
                      'variable' => 'byteString',
                      'expr' => 
                      array (
                        'type' => 'array-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'alphabet',
                          'file' => '/app/phalcon/Security/Random.zep',
                          'line' => 435,
                          'char' => 38,
                        ),
                        'right' => 
                        array (
                          'type' => 'cast',
                          'left' => 'int',
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'idx',
                            'file' => '/app/phalcon/Security/Random.zep',
                            'line' => 435,
                            'char' => 48,
                          ),
                          'file' => '/app/phalcon/Security/Random.zep',
                          'line' => 435,
                          'char' => 48,
                        ),
                        'file' => '/app/phalcon/Security/Random.zep',
                        'line' => 435,
                        'char' => 49,
                      ),
                      'file' => '/app/phalcon/Security/Random.zep',
                      'line' => 435,
                      'char' => 49,
                    ),
                  ),
                  'file' => '/app/phalcon/Security/Random.zep',
                  'line' => 436,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Security/Random.zep',
              'line' => 438,
              'char' => 14,
            ),
            4 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'byteString',
                'file' => '/app/phalcon/Security/Random.zep',
                'line' => 438,
                'char' => 26,
              ),
              'file' => '/app/phalcon/Security/Random.zep',
              'line' => 439,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Generates a random string based on the number ($base) of characters
     * ($alphabet).
     *
     * If $n is not specified, 16 is assumed. It may be larger in future.
     *
     * @throws Exception If secure random number generator is not available or unexpected partial read
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'string',
                'mandatory' => 0,
                'file' => '/app/phalcon/Security/Random.zep',
                'line' => 419,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Security/Random.zep',
            'line' => 419,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Security/Random.zep',
          'line' => 418,
          'last-line' => 440,
          'char' => 22,
        ),
      ),
      'file' => '/app/phalcon/Security/Random.zep',
      'line' => 85,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Security/Random.zep',
    'line' => 85,
    'char' => 5,
  ),
);