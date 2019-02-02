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

/**
 * Class GetTitleCest
 */
class GetTitleCest
{
    /**
     * Tests Phalcon\Tag :: getTitle() - with malicious code
     *
     * @param UnitTester $I
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/11185
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2016-01-13
     */
    public function tagGetTitleWithMaliciousContent(UnitTester $I)
    {
        $I->wantToTest("Tag - getTitle() - with malicious code");
        Tag::resetInput();
        $value = "Hello </title><script>alert('Got your nose!');</script><title>";

        Tag::setTitle($value);
        $expected = 'Hello &lt;/title&gt;&lt;script&gt;alert(&#039;'
            . 'Got your nose!&#039;);&lt;/script&gt;&lt;title&gt;';
        $actual   = Tag::getTitle();
        $I->assertEquals($expected, $actual);
    }
}
