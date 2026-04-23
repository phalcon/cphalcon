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

namespace Phalcon\Tests\Unit\Http\Request;

use Phalcon\Tests\Unit\Http\Helper\AbstractHttpBase;

final class RequestTest extends AbstractHttpBase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2014-10-04
     */
    public function testHttpRequestInputPost(): void
    {
        $request = $this->getRequestObject();

        // hasPost empty
        $this->assertFalse($request->hasPost('test'));

        // hasPost not empty
        $_POST['test'] = 1;
        $this->assertTrue($request->hasPost('test'));
        unset($_POST['test']);

        // getPost empty
        $this->assertEmpty($request->getPost('test'));

        // getPost not empty
        $_POST['test'] = 1;
        $this->assertSame(1, $request->getPost('test'));
        unset($_POST['test']);

        // getPost sanitized
        $_POST['test'] = 'lol<';
        $expected      = 'lol&lt;';
        $actual        = $request->getPost('test', 'string');
        unset($_POST['test']);
        $this->assertSame($expected, $actual);

        // getPost sanitized array filter
        $_POST['test'] = 'lol<';
        $expected      = 'lol&lt;';
        $actual        = $request->getPost('test', ['string']);
        unset($_POST['test']);
        $this->assertSame($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2014-10-04
     */
    public function testHttpRequestInputGet(): void
    {
        $request = $this->getRequestObject();

        // hasQuery empty
        $this->assertFalse($request->hasQuery('test'));

        // hasQuery not empty
        $_GET['test'] = 1;
        $this->assertTrue($request->hasQuery('test'));
        unset($_GET['test']);

        // getQuery empty
        $this->assertEmpty($request->getQuery('test'));

        // getQuery not empty
        $_GET['test'] = 1;
        $this->assertSame(1, $request->getQuery('test'));
        unset($_GET['test']);

        // getQuery sanitized
        $_GET['test'] = 'lol<';
        $expected     = 'lol&lt;';
        $actual       = $request->getQuery('test', 'string');
        unset($_GET['test']);
        $this->assertSame($expected, $actual);

        // getQuery sanitized array filter
        $_GET['test'] = 'lol<';
        $expected     = 'lol&lt;';
        $actual       = $request->getQuery('test', ['string']);
        unset($_GET['test']);
        $this->assertSame($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2014-10-04
     */
    public function testHttpRequestInputRequest(): void
    {
        $request = $this->getRequestObject();

        // has empty
        $this->assertFalse($request->has('test'));

        // has not empty
        $_REQUEST['test'] = 1;
        $this->assertTrue($request->has('test'));
        unset($_REQUEST['test']);

        // get empty
        $this->assertEmpty($request->get('test'));

        // get not empty
        $_REQUEST['test'] = 1;
        $this->assertSame(1, $request->get('test'));
        unset($_REQUEST['test']);

        // get sanitized
        $_REQUEST['test'] = 'lol<';
        $expected         = 'lol&lt;';
        $actual           = $request->get('test', 'string');
        unset($_REQUEST['test']);
        $this->assertSame($expected, $actual);

        // get sanitized array filter
        $_REQUEST['test'] = 'lol<';
        $expected         = 'lol&lt;';
        $actual           = $request->get('test', ['string']);
        unset($_REQUEST['test']);
        $this->assertSame($expected, $actual);
    }

    /**
     * @issue https://github.com/phalcon/cphalcon/issues/1265
     */
    public function testRequestGetValueByUsingSeveralMethods(): void
    {
        $request = $this->getRequestObject();

        $_REQUEST = $_GET = $_POST = [
            'string-key' => 'hello',
            'array-key'  => ['string' => 'world'],
        ];

        // get
        $expected = 'hello';
        $actual   = $request->get('string-key', 'string');
        $this->assertSame($expected, $actual);

        $expected = 'hello';
        $actual   = $request->get('string-key', 'string', null, true, true);
        $this->assertSame($expected, $actual);

        $expected = ['string' => 'world'];
        $actual   = $request->get('array-key', 'string');
        $this->assertSame($expected, $actual);

        $expected = ['string' => 'world'];
        $actual   = $request->get('array-key', 'string', null, true, false);
        $this->assertSame($expected, $actual);

        // getQuery
        $expected = 'hello';
        $actual   = $request->getQuery('string-key', 'string');
        $this->assertSame($expected, $actual);

        $expected = 'hello';
        $actual   = $request->getQuery('string-key', 'string', null, true, true);
        $this->assertSame($expected, $actual);

        // getPost
        $expected = 'hello';
        $actual   = $request->getPost('string-key', 'string');
        $this->assertSame($expected, $actual);

        $expected = null;
        $actual   = $request->getPost('unknown-key', 'string', null, true, true);
        $this->assertSame($expected, $actual);

        $expected = ['string' => 'world'];
        $actual   = $request->getPost('array-key', 'stringlegacy');
        $this->assertSame($expected, $actual);

        $expected = null;
        $actual   = $request->getPost('unknown-key', 'stringlegacy', null, true, true);
        $this->assertSame($expected, $actual);
    }

    public function testRequestGetQuery(): void
    {
        $_REQUEST = $_GET = $_POST = [
            'id'    => 1,
            'num'   => 'a1a',
            'age'   => 'aa',
            'phone' => '',
        ];

        $functions = ['get', 'getQuery', 'getPost'];

        foreach ($functions as $function) {
            $request = $this->getRequestObject();

            $this->assertSame(1, $request->$function('id', 'int', 100));
            $this->assertSame(1, $request->$function('num', 'int', 100));
            $this->assertEmpty($request->$function('age', 'int', 100));
            $this->assertEmpty($request->$function('phone', 'int', 100));
            $this->assertSame(100, $request->$function('phone', 'int', 100, true));
        }
    }
}
