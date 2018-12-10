<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Html\Tag;

use Phalcon\Html\Tag;
use UnitTester;
use const PHP_EOL;

/**
 * Class FormEndCest
 *
 * @package Phalcon\Test\Unit\Html\Tag
 */
class FormEndCest
{
    /**
     * Tests Phalcon\Html\Tag :: formEnd()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function htmlTagFormEnd(UnitTester $I)
    {
        $I->wantToTest('Html\Tag - formEnd()');
        $tag = new Tag();

        $expected = '</form>' . PHP_EOL;
        $actual   = $tag->formEnd();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Html\Tag :: formEnd() - no EOL
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function htmlTagFormEndEol(UnitTester $I)
    {
        $I->wantToTest('Html\Tag - formEnd() - no EOL');
        $tag = new Tag();

        $expected = '</form>';
        $actual   = $tag->formEnd(false);
        $I->assertEquals($expected, $actual);
    }
}
