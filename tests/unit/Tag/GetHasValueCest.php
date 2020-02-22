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

namespace Phalcon\Test\Unit\Tag;

use Phalcon\Tag;
use Phalcon\Test\Fixtures\Helpers\TagSetup;
use UnitTester;

use function uniqid;

class GetHasValueCest extends TagSetup
{
    /**
     * Tests Phalcon\Tag :: getValue()/hasValue()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-02-22
     */
    public function tagGetHasValue(UnitTester $I)
    {
        $I->wantToTest('Tag - getValue()/hasValue()');

        $post = $_POST;

        $key   = uniqid('key-');
        $value = uniqid('val-');

        $actual = Tag::getValue($key, ['value' => $value]);
        $I->assertEquals($value, $actual);

        $key   = uniqid('key-');
        $value = uniqid('val-');

        Tag::setDefault($key, $value);

        $key   = uniqid('key-');
        $value = uniqid('val-');

        $_POST = [
            $key => $value
        ];

        $actual = Tag::getValue($key, []);
        $I->assertEquals($value, $actual);

        $_POST = [];

        $key   = uniqid('key-');

        $actual = Tag::getValue($key, []);
        $I->assertNull($actual);

        $_POST = $post;
    }
}
