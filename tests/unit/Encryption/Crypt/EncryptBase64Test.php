<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Encryption\Crypt;

use Phalcon\Encryption\Crypt;
use Phalcon\Tests\AbstractUnitTestCase;

use function md5;
use function substr;
use function uniqid;

final class EncryptBase64Test extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2021-10-18
     */
    public function testEncryptionCryptEncryptBase64(): void
    {
        $tests = [
            md5(uniqid())            => str_repeat('x', mt_rand(1, 255)),
            time() . time()          => str_shuffle('abcdefeghijklmnopqrst'),
            'le$ki12432543543543543' => '',
        ];

        $ciphers = [
            'AES-128-CBC',
            'AES-128-CFB',
            'AES-128-OFB',
            'AES128',
        ];

        $crypt = new Crypt();

        foreach ($ciphers as $cipher) {
            $crypt->setCipher($cipher);

            foreach ($tests as $key => $test) {
                $crypt->setKey(substr($key, 0, 16));

                $encryption = $crypt->encryptBase64($test);
                $actual     = rtrim($crypt->decryptBase64($encryption), "\0");
                $this->assertSame($test, $actual);
            }

            foreach ($tests as $key => $test) {
                $encryption = $crypt->encryptBase64(
                    $test,
                    substr($key, 0, 16)
                );

                $actual = rtrim(
                    $crypt->decryptBase64(
                        $encryption,
                        substr($key, 0, 16)
                    ),
                    "\0"
                );

                $this->assertSame($test, $actual);
            }
        }
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2021-10-18
     */
    public function testEncryptionCryptEncryptBase64Safe(): void
    {
        $key    = substr(md5(uniqid()), 0, 16);
        $source = 'BvQrk+D^b&saR/L#mQig+8V9v^W&S/&moY7';

        $crypt = new Crypt();

        $encrypted = $crypt->encryptBase64($source, $key, true);
        $decrypted = $crypt->decryptBase64($encrypted, $key, true);
        $this->assertSame($source, $decrypted);
    }
}
