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

namespace Phalcon\Tests\Unit\Crypt\PadFactory;

use Codeception\Example;
use Exception;
use Phalcon\Crypt\Crypt;
use Phalcon\Crypt\Padding\Ansi;
use Phalcon\Crypt\Padding\Iso10126;
use Phalcon\Crypt\Padding\IsoIek;
use Phalcon\Crypt\Padding\Noop;
use Phalcon\Crypt\Padding\PadInterface;
use Phalcon\Crypt\Padding\Pkcs7;
use Phalcon\Crypt\Padding\Space;
use Phalcon\Crypt\Padding\Zero;
use Phalcon\Crypt\PadFactory;
use UnitTester;

/**
 * Class NewInstanceCest
 *
 * @package Phalcon\Tests\Unit\Crypt\PadFactory
 */
class NewInstanceCest
{
    /**
     * Tests Phalcon\Crypt\PadFactory :: newInstance()
     *
     * @dataProvider getExamples
     *
     * @param UnitTester $I
     * @param Example    $example
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2021-10-18
     */
    public function cryptPadFactoryNewInstance(UnitTester $I, Example $example)
    {
        $I->wantToTest('Crypt\PadFactory - newInstance() ' . $example[0]);

        $factory = new PadFactory();
        $adapter = $factory->newInstance($example[0]);
        $class   = $example[1];

        $I->assertInstanceOf($class, $adapter);
        $I->assertInstanceOf(PadInterface::class, $adapter);
    }

    /**
     * Tests Phalcon\Crypt\PadFactory :: newInstance() - exception
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2021-10-18
     */
    public function cryptPadFactoryNewInstanceException(UnitTester $I)
    {
        $I->wantToTest('Crypt\PadFactory - newInstance() - exception');

        $I->expectThrowable(
            new Exception("Service unknown is not registered"),
            function () {
                $factory = new PadFactory();
                $adapter = $factory->newInstance("unknown");
            }
        );
    }


    /**
     * Tests Phalcon\Crypt\PadFactory :: padNumberToService()
     *
     * @dataProvider getPadNumberExamples
     *
     * @param UnitTester $I
     * @param Example    $example
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2020-09-09
     */
    public function cryptPadNumberToService(UnitTester $I, Example $example)
    {
        $I->wantToTest('Crypt\PadFactory - padNumberToService() ' . $example[0]);

        $factory = new PadFactory();

        $expected = $example[1];
        $actual   = $factory->padNumberToService($example[0]);
        $I->assertEquals($expected, $actual);
    }

    /**
     * @return array<array-key, array<array-key, string>>
     */
    private function getExamples(): array
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
    private function getPadNumberExamples(): array
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
}
