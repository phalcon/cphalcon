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

namespace Phalcon\Tests\Unit\Mvc\Url;

use Phalcon\Mvc\Url;
use Phalcon\Tests\AbstractUnitTestCase;

final class UrlTest extends AbstractUnitTestCase
{
    /**
     * @author Nikolaos Dimopoulos <nikos@phalcon.io>
     * @since  2014-09-04
     */
    public function testShouldGetCorrectUrlWithServer(): void
    {
        $url = new Url();
        $url->setBaseUri('/');

        $_SERVER['PHP_SELF'] = '/index.php';

        $expected = '/';
        $actual   = $url->get(null);
        $this->assertEquals($expected, $actual);

        $expected = '/classes/api/Some';
        $actual   = $url->get('classes/api/Some');
        $this->assertEquals($expected, $actual);
    }
}
