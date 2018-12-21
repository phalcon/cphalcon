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
 * Class EndFormCest
 *
 * @package Phalcon\Test\Unit\Html\Tag
 */
class EndFormCest
{
    /**
     * Tests Phalcon\Html\Tag :: endForm()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function htmlTagEndForm(UnitTester $I)
    {
        $I->wantToTest('Html\Tag - endForm()');
        $tag = new Tag();

        $expected = '</form>';
        $actual   = $tag->endForm(false);
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Html\Tag :: endForm() - EOL
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function htmlTagEndFormEol(UnitTester $I)
    {
        $I->wantToTest('Html\Tag - endForm() - EOL');
        $tag = new Tag();

        $expected = '</form>' . PHP_EOL;
        $actual   = $tag->endForm();
        $I->assertEquals($expected, $actual);
    }
}
