<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Integration\Session\Adapter;

use IntegrationTester;
use Phalcon\Session\Adapter;
use Phalcon\Session\Adapter\Files;
use function outputFolder;

class FilesCest
{
    protected $sessionConfig = [];

    public function _before(IntegrationTester $I)
    {
        $I->skipTest('REFACTOR');
        $this->sessionConfig = [
            'save_handler'      => ini_get('session.save_handler'),
            'save_path'         => ini_get('session.save_path'),
            'serialize_handler' => ini_get('session.serialize_handler'),
        ];

        if (!isset($_SESSION)) {
            $_SESSION = [];
        }
    }

    public function _after(IntegrationTester $I)
    {
        if (PHP_SESSION_ACTIVE == session_status()) {
            session_destroy();
        }

        foreach ($this->sessionConfig as $key => $val) {
            ini_set($key, $val);
        }
    }

    public function testSessionName(IntegrationTester $I)
    {
        $session = new Files();
        $session->setName('NAMEFOO');

        $I->assertEquals($session->getName(), 'NAMEFOO');
        $I->assertEquals(session_name(), 'NAMEFOO');

        session_name('NAMEBAR');
        $I->assertEquals($session->getName(), 'NAMEBAR');
    }

    /**
     * Tests session start
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2016-01-20
     */
    public function testSessionStart(IntegrationTester $I)
    {
        $session = new Files();

        $I->assertTrue($session->start());
        $I->assertTrue($session->isStarted());
        $I->assertEquals($session->status(), Adapter::SESSION_ACTIVE);
    }

    /**
     * Tests session start
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/10238
     * @author Phalcon Team <team@phalconphp.com>
     * @author Dreamszhu <dreamsxin@qq.com>
     * @since  2016-01-20
     */
    public function testSessionFilesGet(IntegrationTester $I)
    {
        $session = new Files();

        session_start();

        $session->set('some', 'value');

        $I->assertEquals($session->get('some'), 'value');
        $I->assertTrue($session->has('some'));
        $I->assertEquals($session->get('undefined', 'my-default'), 'my-default');

        $I->assertEquals($session->get('some', null, true), 'value');
        $I->assertFalse($session->has('some'));

        $session->set('some_zero', 0);
        $I->assertTrue($session->get('some_zero') === 0);
        $I->assertFalse($session->get('some_zero') === null);

        $session->set('some_false', false);
        $I->assertFalse($session->get('some_false') === null);
        $I->assertTrue($session->get('some_false') === false);
    }

    /**
     * Tests session write
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2016-01-24
     */
    public function testSessionFilesWrite(IntegrationTester $I)
    {
        $path = outputFolder(
            sprintf('tests%ssession%s', DIRECTORY_SEPARATOR, DIRECTORY_SEPARATOR)
        );

        ini_set('session.save_handler', 'files');
        ini_set('session.save_path', $path);
        ini_set('session.serialize_handler', 'php');

        $session = new Files();
        $session->start();

        $session->set('some', 'write-value');

        $I->assertNotEmpty($id = $session->getId());

        $file = sprintf('%ssess_%s', $path, $id);
        unset($session);

        $I->openFile($file);
        $I->seeInThisFile('some|s:11:"write-value";');

        $I->safeDeleteFile($file);
    }

    /**
     * Tests session write with magic __set
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2016-01-24
     */
    public function testSessionFilesWriteMagic(IntegrationTester $I)
    {
        $path = outputFolder(
            sprintf('tests%ssession%s', DIRECTORY_SEPARATOR, DIRECTORY_SEPARATOR)
        );

        ini_set('session.save_handler', 'files');
        ini_set('session.save_path', $path);
        ini_set('session.serialize_handler', 'php');

        $session = new Files();
        $session->start();

        $session->some = 'write-magic-value';

        $I->assertNotEmpty($id = $session->getId());

        $file = sprintf('%ssess_%s', $path, $id);
        unset($session);

        $I->openFile($file);
        $I->seeInThisFile('some|s:17:"write-magic-value";');

        $I->safeDeleteFile($file);
    }

    /**
     * Tests session read
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2016-01-24
     */
    public function testSessionFilesRead(IntegrationTester $I)
    {
        $id   = md5(microtime(true));
        $path = outputFolder(
            sprintf('tests%ssession%s', DIRECTORY_SEPARATOR, DIRECTORY_SEPARATOR)
        );
        $file = sprintf('%ssess_%s', $path, $id);

        $session = new Files();
        $session->setId($id);
        $session->start();

        $_SESSION['some'] = 'read-value';

        $I->assertTrue($session->has('some'));
        $I->assertEquals($session->get('some'), 'read-value');

        $session->destroy();

        $I->dontSeeFileFound($file);
    }

    /**
     * Tests session read with magic __get
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2016-01-24
     */
    public function testSessionFilesReadMagic(IntegrationTester $I)
    {
        $id   = md5(microtime(true));
        $path = outputFolder(
            sprintf('tests%ssession%s', DIRECTORY_SEPARATOR, DIRECTORY_SEPARATOR)
        );
        $file = sprintf('%ssess_%s', $path, $id);

        $session = new Files();
        $session->setId($id);
        $session->start();

        $_SESSION['some'] = 'read-magic-value';

        $I->assertTrue(isset($session->some));
        $I->assertEquals($session->some, 'read-magic-value');

        unset($session->some);
        $I->assertFalse(isset($session->some));

        $session->destroy();

        $I->dontSeeFileFound($file);
    }

    /**
     * Tests the destroy with cleanning $_SESSION
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/12326
     * @issue  https://github.com/phalcon/cphalcon/issues/12835
     * @author Serghei Iakovelev <serghei@phalconphp.com>
     * @since  2017-05-08
     */
    public function destroyDataFromSessionSuperGlobal(IntegrationTester $I)
    {
        $session = new Files([
            'uniqueId' => 'session',
            'lifetime' => 3600,
        ]);

        $session->start();

        $session->test1 = __METHOD__;
        $I->assertArrayHasKey('session#test1', $_SESSION);
        $I->assertContains(__METHOD__, $_SESSION['session#test1']);

        // @deprecated See: https://github.com/phalcon/cphalcon/issues/12833
        $session->destroy(true);
        $I->assertArrayNotHasKey('session#test1', $_SESSION);
    }
}
