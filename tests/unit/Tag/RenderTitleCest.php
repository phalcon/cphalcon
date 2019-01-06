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

class RenderTitleCest
{
    /**
     * Tests Phalcon\Tag :: renderTitle() - with malicious code
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-01
     */
    public function tatRenderTitleWithMaliciousContent(UnitTester $I)
    {
        $I->wantToTest("Tag - renderTitle() - with malicious code");
        Tag::resetInput();
        $value = "Hello </title><script>alert('Got your nose!');</script><title>";

        Tag::setTitle($value);
        $expected = '<title>Hello &lt;/title&gt;&lt;script&gt;alert(&#039;'
            . 'Got your nose!&#039;);&lt;/script&gt;&lt;title&gt;</title>' . PHP_EOL;
        $actual   = Tag::renderTitle();
        $I->assertEquals($expected, $actual);
    }
}
