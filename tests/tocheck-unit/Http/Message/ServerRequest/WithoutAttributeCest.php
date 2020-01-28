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

namespace Phalcon\Test\Unit\Http\Message\ServerRequest;

use Phalcon\Http\Message\ServerRequest;
use UnitTester;

class WithoutAttributeCest
{
    /**
     * Tests Phalcon\Http\Message\ServerRequest :: withoutAttribute()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-02-10
     */
    public function httpMessageServerRequestWithoutAttribute(UnitTester $I)
    {
        $I->wantToTest('Http\Message\ServerRequest - withoutAttribute()');

        $request = (new ServerRequest())
            ->withAttribute('one', 'two')
            ->withAttribute('three', 'four')
        ;

        $newInstance = $request->withoutAttribute('one');

        $I->assertNotEquals($request, $newInstance);

        $I->assertEquals(
            [
                'three' => 'four',
            ],
            $newInstance->getAttributes()
        );
    }
}
