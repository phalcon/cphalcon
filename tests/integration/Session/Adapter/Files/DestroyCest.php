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
use function uniqid;

/**
 * Class DestroyCest
 */
class DestroyCest
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
     * Tests Phalcon\Session\Adapter\Files :: destroy()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function sessionAdapterFilesDestroy(IntegrationTester $I)
    {
        $I->wantToTest('Session\Adapter\Files - destroy()');
        $adapter = $this->getSessionFiles();

        /**
         * Create a file in the session folder
         */
        file_put_contents(cacheFolder('test1'), uniqid());
        $actual = $adapter->destroy('test1');
        $I->assertTrue($actual);

        $I->dontSeeFileFound('test1', cacheFolder());
    }
}
