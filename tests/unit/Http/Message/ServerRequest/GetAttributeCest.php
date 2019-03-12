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

namespace Phalcon\Test\Unit\Http\Message\ServerRequest;

use Phalcon\Http\Message\ServerRequest;
use UnitTester;

/**
 * Class GetAttributeCest
 */
class GetAttributeCest
{
    /**
     * Tests Phalcon\Http\Message\ServerRequest :: getAttribute()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-11
     */
    public function httpMessageServerRequestGetAttribute(UnitTester $I)
    {
        $I->wantToTest('Http\Message\ServerRequest - getAttribute()');
        $request = (new ServerRequest())
            ->withAttribute('one', 'two')
            ->withAttribute('three', 'four')
        ;

        $expected = 'two';
        $actual   = $request->getAttribute('one');
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Http\Message\ServerRequest :: getAttribute() - unknown
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-11
     */
    public function httpMessageServerRequestGetAttributeUnknown(UnitTester $I)
    {
        $I->wantToTest('Http\Message\ServerRequest - getAttribute() - unknown');
        $request = (new ServerRequest())
            ->withAttribute('one', 'two')
            ->withAttribute('three', 'four')
        ;

        $expected = '';
        $actual   = $request->getAttribute('unknown');
        $I->assertEquals($expected, $actual);
    }
}
