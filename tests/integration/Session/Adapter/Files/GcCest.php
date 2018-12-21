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

namespace Phalcon\Test\Integration\Session\Adapter\Files;

use IntegrationTester;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use Phalcon\Test\Fixtures\Traits\SessionTrait;
use function cacheFolder;
use function file_put_contents;
use function sleep;
use function uniqid;

/**
 * Class GcCest
 */
class GcCest
{
    use DiTrait;
    use SessionTrait;

    /**
     * @param IntegrationTester $I
     */
    public function _before(IntegrationTester $I)
    {
        $this->newFactoryDefault();
    }

    /**
     * Tests Phalcon\Session\Adapter\Files :: gc()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function sessionAdapterFilesGc(IntegrationTester $I)
    {
        $I->wantToTest('Session\Adapter\Files - gc()');
        $adapter = $this->getSessionFiles();

        /**
         * Add two session files
         */
        file_put_contents(cacheFolder('gc_1'), uniqid());
        file_put_contents(cacheFolder('gc_2'), uniqid());
        /**
         * Sleep to make sure that the time expired
         */
        sleep(2);
        $actual = $adapter->gc(1);
        $I->assertTrue($actual);
        $I->amInPath(cacheFolder());
        $I->dontSeeFileFound('gc_1');
        $I->dontSeeFileFound('gc_2');
    }
}
