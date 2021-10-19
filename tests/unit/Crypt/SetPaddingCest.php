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

namespace Phalcon\Tests\Unit\Crypt;

use Codeception\Example;
use Phalcon\Crypt\Crypt;
use Phalcon\Crypt\Exception\Exception;
use Phalcon\Crypt\Exception\Mismatch;
use UnitTester;

class SetPaddingCest
{
    /**
     * Tests Phalcon\Crypt\Crypt :: setPadding()
     *
     * @dataProvider getExamples
     *
     * @param UnitTester $I
     * @param Example    $example
     *
     * @throws Exception
     * @throws Mismatch
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2021-10-18
     */
    public function cryptSetPadding(UnitTester $I, Example $example)
    {
        $I->wantToTest('Crypt - setPadding() - ' . $example['label']);

        $texts = [
            '',
        ];

        $key = '0123456789ABCDEF0123456789ABCDEF';

        for ($i = 1; $i < 128; ++$i) {
            $texts[] = str_repeat('A', $i);
        }

        $crypt = new Crypt();
        $crypt
            ->setKey($key)
            ->useSigning($example['sign'])
            ->setPadding($example['padding'])
            ->setCipher($example['cipher'])
        ;

        foreach ($texts as $source) {
            $encrypted = $crypt->encrypt($source);
            $expected  = $source;
            $actual    = $crypt->decrypt($encrypted);
            $I->assertEquals($expected, $actual);
        }
    }

    /**
     * @return array[]
     */
    private function getExamples(): array
    {
        $ciphers = [
            'AES-256-CBC',
            'AES-256-CFB',
        ];
        $paddings = [
            Crypt::PADDING_ANSI_X_923     => 'PADDING_ANSI_X_923',
            Crypt::PADDING_PKCS7          => 'PADDING_PKCS7',
            Crypt::PADDING_ISO_10126      => 'PADDING_ISO_10126',
            Crypt::PADDING_ISO_IEC_7816_4 => 'PADDING_ISO_IEC_7816_4',
            Crypt::PADDING_ZERO           => 'PADDING_ZERO',
            Crypt::PADDING_SPACE          => 'PADDING_SPACE',
        ];
        $signed  = [
            'unsigned' => false,
            'signed'   => true,
        ];

        $result = [];
        foreach ($ciphers as $cipher) {
            foreach ($signed as $signedLabel => $signedValue) {
                foreach ($paddings as $padding => $paddingLabel) {
                    $result[] = [
                        'label'   => $cipher . ' - ' . $paddingLabel . ' - ' . $signedLabel,
                        'cipher'  => $cipher,
                        'padding' => $padding,
                        'sign'    => $signedValue,
                    ];
                }
            }
        }

        return $result;
    }
}
