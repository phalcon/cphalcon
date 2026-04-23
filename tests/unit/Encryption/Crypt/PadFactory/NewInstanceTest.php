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

namespace Phalcon\Tests\Unit\Encryption\Crypt\PadFactory;

use Exception;
use Phalcon\Encryption\Crypt;
use Phalcon\Encryption\Crypt\Padding\Ansi;
use Phalcon\Encryption\Crypt\Padding\Iso10126;
use Phalcon\Encryption\Crypt\Padding\IsoIek;
use Phalcon\Encryption\Crypt\Padding\Noop;
use Phalcon\Encryption\Crypt\Padding\PadInterface;
use Phalcon\Encryption\Crypt\Padding\Pkcs7;
use Phalcon\Encryption\Crypt\Padding\Space;
use Phalcon\Encryption\Crypt\Padding\Zero;
use Phalcon\Encryption\Crypt\PadFactory;
use Phalcon\Tests\AbstractUnitTestCase;

final class NewInstanceTest extends AbstractUnitTestCase
{
    /**
     * @return array<array-key, array<array-key, string>>
     */
    public static function getExamples(): array
    {
        return [
            [
                "ansi",
                Ansi::class,
            ],
            [
                "iso10126",
                Iso10126::class,
            ],
            [
                "isoiek",
                IsoIek::class,
            ],
            [
                "noop",
                Noop::class,
            ],
            [
                "pjcs7",
                Pkcs7::class,
            ],
            [
                "space",
                Space::class,
            ],
            [
                "zero",
                Zero::class,
            ],
            [
                "noop",
                Noop::class,
            ],
        ];
    }

    /**
     * @return array<array-key, array<array-key, int|string>>
     */
    public static function getPadNumberExamples(): array
    {
        return [
            [
                Crypt::PADDING_ANSI_X_923,
                "ansi",
            ],
            [
                Crypt::PADDING_ISO_10126,
                "iso10126",
            ],
            [
                Crypt::PADDING_ISO_IEC_7816_4,
                "isoiek",
            ],
            [
                Crypt::PADDING_PKCS7,
                "pjcs7",
            ],
            [
                Crypt::PADDING_SPACE,
                "space",
            ],
            [
                Crypt::PADDING_ZERO,
                "zero",
            ],
            [
                Crypt::PADDING_DEFAULT,
                "noop",
            ],
            [
                100,
                "noop",
            ],
        ];
    }

    /**
     * @dataProvider getExamples
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2021-10-18
     */
    public function testEncryptionCryptPadFactoryNewInstance(
        string $name,
        string $class
    ): void {
        $factory = new PadFactory();
        $adapter = $factory->newInstance($name);

        $this->assertInstanceOf($class, $adapter);
        $this->assertInstanceOf(PadInterface::class, $adapter);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2021-10-18
     */
    public function testEncryptionCryptPadFactoryNewInstanceException(): void
    {
        $this->expectException(Exception::class);
        $this->expectExceptionMessage("Service unknown is not registered");

        $factory = new PadFactory();
        $factory->newInstance("unknown");
    }

    /**
     * @dataProvider getPadNumberExamples
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2021-10-18
     */
    public function testEncryptionCryptPadNumberToService(
        int $padding,
        string $expected
    ): void {
        $factory = new PadFactory();

        $actual = $factory->padNumberToService($padding);
        $this->assertSame($expected, $actual);
    }
}
