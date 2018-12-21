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
use function uniqid;

/**
 * Class WriteCest
 */
class WriteCest
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
     * Tests Phalcon\Session\Adapter\Files :: write()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function sessionAdapterFilesWrite(IntegrationTester $I)
    {
        $I->wantToTest('Session\Adapter\Files - write()');
        $adapter = $this->getSessionFiles();
        $value   = uniqid();
        $adapter->write('test1', $value);
        $I->amInPath(cacheFolder());
        $I->seeFileFound('test1');
        $I->seeInThisFile($value);
        $I->safeDeleteFile(cacheFolder('test1'));
    }
}
