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

namespace Phalcon\Tests\Integration\Session\Adapter\Stream;

use IntegrationTester;
use Phalcon\Tests\Fixtures\Traits\DiTrait;
use Phalcon\Tests\Fixtures\Traits\SessionTrait;

use function cacheDir;
use function file_put_contents;
use function sleep;
use function uniqid;

class GcCest
{
    use DiTrait;

    /**
     * Tests Phalcon\Session\Adapter\Stream :: gc()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function sessionAdapterStreamGc(IntegrationTester $I)
    {
        $I->wantToTest('Session\Adapter\Stream - gc()');

        $adapter = $this->newService('sessionStream');

        /**
         * Add two session files
         */
        $I->assertNotFalse(
            file_put_contents(
                cacheDir('sessions/gc_1'),
                uniqid()
            )
        );

        $I->assertNotFalse(
            file_put_contents(
                cacheDir('sessions/gc_2'),
                uniqid()
            )
        );

        /**
         * Sleep to make sure that the time expired
         */
        sleep(2);

        $I->assertTrue(
            $adapter->gc(1)
        );

        $I->dontSeeFileFound('gc_1', cacheDir('sessions'));
        $I->dontSeeFileFound('gc_2', cacheDir('sessions'));
    }
}
