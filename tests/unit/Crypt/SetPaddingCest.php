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
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2014-10-17
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
        return [
            [
                'label'   => 'AES-256-CBC - PADDING_ANSI_X_923',
                'cipher'  => 'AES-256-CBC',
                'padding' => Crypt::PADDING_ANSI_X_923,
            ],
            [
                'label'   => 'AES-256-CBC - PADDING_PKCS7',
                'cipher'  => 'AES-256-CBC',
                'padding' => Crypt::PADDING_PKCS7,
            ],
            [
                'label'   => 'AES-256-CBC - PADDING_ISO_10126',
                'cipher'  => 'AES-256-CBC',
                'padding' => Crypt::PADDING_ISO_10126,
            ],
            [
                'label'   => 'AES-256-CBC - PADDING_ISO_IEC_7816_4',
                'cipher'  => 'AES-256-CBC',
                'padding' => Crypt::PADDING_ISO_IEC_7816_4,
            ],
            [
                'label'   => 'AES-256-CBC - PADDING_ZERO',
                'cipher'  => 'AES-256-CBC',
                'padding' => Crypt::PADDING_ZERO,
            ],
            [
                'label'   => 'AES-256-CBC - PADDING_SPACE',
                'cipher'  => 'AES-256-CBC',
                'padding' => Crypt::PADDING_SPACE,
            ],
            [
                'label'   => 'AES-256-CFB - PADDING_ANSI_X_923',
                'cipher'  => 'AES-256-CFB',
                'padding' => Crypt::PADDING_ANSI_X_923,
            ],
            [
                'label'   => 'AES-256-CFB - PADDING_PKCS7',
                'cipher'  => 'AES-256-CFB',
                'padding' => Crypt::PADDING_PKCS7,
            ],
            [
                'label'   => 'AES-256-CFB - PADDING_ISO_10126',
                'cipher'  => 'AES-256-CFB',
                'padding' => Crypt::PADDING_ISO_10126,
            ],
            [
                'label'   => 'AES-256-CFB - PADDING_ISO_IEC_7816_4',
                'cipher'  => 'AES-256-CFB',
                'padding' => Crypt::PADDING_ISO_IEC_7816_4,
            ],
            [
                'label'   => 'AES-256-CFB - PADDING_ZERO',
                'cipher'  => 'AES-256-CFB',
                'padding' => Crypt::PADDING_ZERO,
            ],
            [
                'label'   => 'AES-256-CFB - PADDING_SPACE',
                'cipher'  => 'AES-256-CFB',
                'padding' => Crypt::PADDING_SPACE,
            ],
        ];
    }
}
