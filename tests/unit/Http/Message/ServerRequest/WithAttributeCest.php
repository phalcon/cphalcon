<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Http\Message\ServerRequest;

use Phalcon\Http\Message\ServerRequest;
use UnitTester;

class WithAttributeCest
{
    /**
     * Tests Phalcon\Http\Message\ServerRequest :: withAttribute()
     *
     * @since  2019-02-10
     */
    public function httpMessageServerRequestWithAttribute(UnitTester $I)
    {
        $I->wantToTest('Http\Message\ServerRequest - withAttribute()');
        $request     = new ServerRequest();
        $newInstance = $request->withAttribute('one', 'two');

        $I->assertNotEquals($request, $newInstance);
        $I->assertEquals('two', $newInstance->getAttribute('one'));
    }
}
