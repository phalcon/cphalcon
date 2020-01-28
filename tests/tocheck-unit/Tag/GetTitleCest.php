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
use UnitTester;

class GetTitleCest
{
    /**
     * Tests Phalcon\Tag :: getTitle() - with malicious code
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/11185
     * @author Phalcon Team <team@phalcon.io>
     * @since  2016-01-13
     */
    public function tagGetTitleWithMaliciousContent(UnitTester $I)
    {
        $I->wantToTest('Tag - getTitle() - with malicious code');

        Tag::resetInput();

        Tag::setTitle(
            "Hello </title><script>alert('Got your nose!');</script><title>"
        );

        $I->assertEquals(
            'Hello &lt;/title&gt;&lt;script&gt;alert(&#039;Got your nose!&#039;);&lt;/script&gt;&lt;title&gt;',
            Tag::getTitle()
        );
    }
}
