<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Html\Helper\Meta;

use Phalcon\Html\Escaper;
use Phalcon\Html\Helper\Meta;
use UnitTester;

use const PHP_EOL;

/**
 * Class ToStringCest
 *
 * @package Phalcon\Tests\Unit\Html\Helper\Meta
 */
class ToStringCest
{
    /**
     * Tests Phalcon\Html\Helper\Meta :: __toString() - empty
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function htmlHelperMetaToStringEmpty(UnitTester $I)
    {
        $I->wantToTest('Html\Helper\Meta - __toString() - empty');

        $escaper = new Escaper();
        $helper  = new Meta($escaper);

        $result = $helper();

        $actual = (string)$result;
        $I->assertEmpty($actual);
    }

    /**
     * Tests Phalcon\Html\Helper\Meta :: __toString() - retains value
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2023-09-26
     * @issue  https://github.com/phalcon/cphalcon/issues/16441
     */
    public function htmlHelperMetaToStringRetainsValue(UnitTester $I)
    {
        $I->wantToTest('Html\Helper\Meta - __toString() - retains value');

        $escaper = new Escaper();
        $meta    = new Meta($escaper);
        $meta
            ->addName('robots', 'index, nofollow')
            ->addName('author', 'Me')
        ;

        $expected = '    <meta name="robots" content="index, nofollow">'
            . PHP_EOL
            . '    <meta name="author" content="Me">'
            . PHP_EOL;
        $actual   = (string)$meta;
        $I->assertSame($expected, $actual);

        $meta = new Meta($escaper);
        $meta->addName('robots', 'index, nofollow');

        $expected = '    <meta name="robots" content="index, nofollow">'
            . PHP_EOL
            . '    <meta name="author" content="Me">'
            . PHP_EOL;
        $actual   = (string)$meta->addName('author', 'Me');
        $I->assertSame($expected, $actual);
    }
}
