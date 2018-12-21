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
 * Class HasValueCest
 *
 * @package Phalcon\Test\Unit\Html\Tag
 */
class HasValueCest
{
    /**
     * Tests Phalcon\Html\Tag :: hasValue()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function htmlTagHasValue(UnitTester $I)
    {
        $I->wantToTest('Html\Tag - hasValue()');
        $tag = new Tag();

        $tag->setAttribute('name', 'Phalcon');

        $actual = $tag->hasValue('name');
        $I->assertTrue($actual);
    }

    /**
     * Tests Phalcon\Html\Tag :: hasValue() - POST
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function htmlTagHasValuePost(UnitTester $I)
    {
        $I->wantToTest('Html\Tag - hasValue() - POST');
        $tag = new Tag();

        $oldPost       = $_POST;
        $_POST         = [];
        $_POST['name'] = 'Phalcon';

        $actual = $tag->hasValue('name');
        $I->assertTrue($actual);

        $_POST = $oldPost;
    }
}
