<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the
 * LICENSE.txt file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Test\Unit\Http\Response;

use InvalidArgumentException;
use Phalcon\Http\Response;
use UnitTester;
use TypeError;

class ConstructCest
{
    /**
     * Tests Phalcon\Http\Response :: __construct()
     *
     * @param  UnitTester $I
     *
     * @author Jeremy PASTOURET <https://github.com/jenovateurs>
     * @since  2019-12-08
     */
    public function httpResponseConstruct(UnitTester $I)
    {
        $I->wantToTest('Http\Response - __construct()');

        $oResponse = new Response();

        $I->assertInstanceOf(
            Response::class,
            $oResponse
        );
    }

    /**
     * Tests Phalcon\Http\Response :: __construct(content = [array])
     *
     * @param  UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-05-02
     */
    public function httpResponseConstructWithIncorrectDataType(UnitTester $I)
    {
        $I->wantToTest('Http\Response - __construct(content = [array])');

        if (version_compare(PHP_VERSION, '8.0.0', '>=')) {
            $throwable = new TypeError(
                sprintf(
                    'Phalcon\Http\Response::__construct(): Argument #1 ($content) must be of type ?string, array given',
                    Response::class
                )
            );
        } else {
            $throwable = new TypeError(
                sprintf(
                    'Argument 1 passed to %s::__construct() must be of the type string or null, array given',
                    Response::class
                )
            );
        }

        $I->expectThrowable($throwable, function () {
            new Response(['Put a Sock In It']);
        });
    }

    /**
     * Tests Phalcon\Http\Response :: __construct(content = null)
     *
     * @param  UnitTester $I
     *
     * @author Jeremy PASTOURET <https://github.com/jenovateurs>
     * @since  2019-12-08
     */
    public function httpResponseConstructWithContent(UnitTester $I)
    {
        $I->wantToTest('Http\Response - __construct(content = null)');

        $content = '<h1>Money Doesn\'t Grow On Trees</h1>';

        $oResponse = new Response($content);

        $I->assertSame(
            $content,
            $oResponse->getContent()
        );
    }

    /**
     * Tests Phalcon\Http\Response :: __construct(content = null, code = null)
     *
     * @param  UnitTester $I
     *
     * @author Jeremy PASTOURET <https://github.com/jenovateurs>
     * @since  2019-12-08
     */
    public function httpResponseConstructWithContentCode(UnitTester $I)
    {
        $I->wantToTest('Http\Response - __construct(content = null, code = null)');

        $content = '<h1>Elephant in the Room</h1>';

        $nCodeSuccess = 200;

        $oResponse = new Response($content, $nCodeSuccess);

        $I->assertSame(
            $content,
            $oResponse->getContent()
        );

        $I->assertSame(
            $nCodeSuccess,
            $oResponse->getStatusCode()
        );

        //Check Status message
        $I->assertSame(
            '200 OK',
            $oResponse->getHeaders()->get('Status')
        );
    }

    /**
     * Tests Phalcon\Http\Response :: __construct(content = null, code = null,
     * status = null)
     *
     * @param  UnitTester $I
     *
     * @author Jeremy PASTOURET <https://github.com/jenovateurs>
     * @since  2019-12-08
     */
    public function httpResponseConstructWithContentCodeStatus(UnitTester $I)
    {
        $I->wantToTest('Http\Response - __construct(content = null, code = null, status = null)');

        $content = '<h1>Fight Fire With Fire</h1>';

        $nCodeSuccess = 200;

        $oResponse = new Response($content, $nCodeSuccess, 'Success');

        $I->assertSame(
            $content,
            $oResponse->getContent()
        );

        $I->assertSame(
            $nCodeSuccess,
            $oResponse->getStatusCode()
        );

        //Check Status message
        $I->assertSame(
            '200 Success',
            $oResponse->getHeaders()->get('Status')
        );
    }
}
