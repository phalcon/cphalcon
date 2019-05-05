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

namespace Phalcon\Test\Unit\Tag;

use Phalcon\Tag;
use UnitTester;

class SetTitleCest
{
    /**
     * Tests Phalcon\Tag :: setTitle()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function tagSetTitle(UnitTester $I)
    {
        $I->wantToTest("Tag - setTitle()");

        Tag::resetInput();

        $value = 'This is my title';

        Tag::setTitle($value);

        $I->assertEquals(
            "<title>{$value}</title>" . PHP_EOL,
            Tag::renderTitle()
        );

        $I->assertEquals(
            "{$value}",
            Tag::getTitle()
        );
    }
}
