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

/**
 * Class GetValueCest
 *
 * @package Phalcon\Test\Unit\Html\Tag
 */
class GetValueCest
{
    /**
     * Tests Phalcon\Html\Tag :: getValue()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function htmlTagGetValue(UnitTester $I)
    {
        $I->wantToTest('Html\Tag - getValue()');
        $tag = new Tag();

        $attributes = ['value' => 'Phalcon'];
        $expected   = 'Phalcon';
        $actual     = $tag->getValue('name', $attributes);
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Html\Tag :: getValue() - internal array
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function htmlTagGetValueInternal(UnitTester $I)
    {
        $I->wantToTest('Html\Tag - getValue() - internal array');
        $tag = new Tag();

        $tag->setAttribute('name', 'Phalcon');
        $expected = 'Phalcon';
        $actual   = $tag->getValue('name');
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Html\Tag :: getValue() - POST
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function htmlTagGetValuePost(UnitTester $I)
    {
        $I->wantToTest('Html\Tag - getValue() - POST');
        $tag = new Tag();

        $oldPost       = $_POST;
        $_POST         = [];
        $_POST['name'] = 'Phalcon';

        $expected = 'Phalcon';
        $actual   = $tag->getValue('name');
        $I->assertEquals($expected, $actual);

        $_POST = $oldPost;
    }
}
