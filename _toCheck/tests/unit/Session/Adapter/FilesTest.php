<?php

namespace Phalcon\Test\Unit\Session\Adapter;

use Phalcon\Session\Adapter;
use Phalcon\Test\Module\UnitTest;
use Phalcon\Session\Adapter\Files;

/**
 * Phalcon\Test\Unit\Session\Adapter\FilesTest
 * Tests the \Phalcon\Session\Adapter\Files component
 *
 * @copyright (c) 2011-2017 Phalcon Team
 * @link      https://phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Nikolaos Dimopoulos <nikos@phalconphp.com>
 * @package   Phalcon\Test\Unit\Session\Adapter
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class FilesTest extends UnitTest
{
    protected $sessionConfig = [];

    /**
     * executed before each test
     */
    protected function _before()
    {
        parent::_before();

        $this->sessionConfig = [
            'save_handler'      => ini_get('session.save_handler'),
            'save_path'         => ini_get('session.save_path'),
            'serialize_handler' => ini_get('session.serialize_handler'),
        ];

        if (!isset($_SESSION)) {
            $_SESSION = [];
        }
    }

    /**
     * executed after each test
     */
    protected function _after()
    {
        parent::_after();

        if (PHP_SESSION_ACTIVE == session_status()) {
            session_destroy();
        }

        foreach ($this->sessionConfig as $key => $val) {
            ini_set($key, $val);
        }
    }

    public function testSessionName()
    {
        $this->specify(
            'The Files Adapter is handling the named session incorrectly',
            function () {
                $session = new Files();
                $session->setName('NAMEFOO');

                expect($session->getName())->equals('NAMEFOO');
                expect(session_name())->equals('NAMEFOO');

                session_name('NAMEBAR');
                expect($session->getName())->equals('NAMEBAR');
            }
        );
    }

    /**
     * Tests session start
     *
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-01-20
     */
    public function testSessionStart()
    {
        $this->specify(
            'Headers not sent yet but the session can not be started',
            function () {
                $session = new Files();

                expect($session->start())->true();
                expect($session->isStarted())->true();
                expect($session->status())->equals(Adapter::SESSION_ACTIVE);
            }
        );
    }

    /**
     * Tests session start
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/10238
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @author Dreamszhu <dreamsxin@qq.com>
     * @since  2016-01-20
     */
    public function testSessionFilesGet()
    {
        $this->specify(
            'Session getter does not work correctly',
            function () {
                $session = new Files();

                session_start();

                $session->set('some', 'value');

                expect($session->get('some'))->equals('value');
                expect($session->has('some'))->true();
                expect($session->get('undefined', 'my-default'))->equals('my-default');

                expect($session->get('some', null, true))->equals('value');
                expect($session->has('some'))->false();

                $session->set('some_zero', 0);
                expect($session->get('some_zero') === 0)->true();
                expect($session->get('some_zero') === null)->false();

                $session->set('some_false', false);
                expect($session->get('some_false') === null)->false();
                expect($session->get('some_false') === false)->true();
            }
        );
    }

    /**
     * Tests session write
     *
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-01-24
     */
    public function testSessionFilesWrite()
    {
        $this->specify(
            'Files session does not write data correctly',
            function () {
                $I    = $this->tester;
                $path = PATH_OUTPUT . sprintf('tests%ssession%s', DIRECTORY_SEPARATOR, DIRECTORY_SEPARATOR);

                ini_set('session.save_handler', 'files');
                ini_set('session.save_path', $path);
                ini_set('session.serialize_handler', 'php');

                $session = new Files();
                $session->start();

                $session->set('some', 'write-value');

                expect($id = $session->getId())->notEmpty();

                $file = sprintf('%ssess_%s', $path, $id);
                unset($session);

                $I->openFile($file);
                $I->seeInThisFile('some|s:11:"write-value";');

                $I->deleteFile($file);
            }
        );
    }

    /**
     * Tests session write with magic __set
     *
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-01-24
     */
    public function testSessionFilesWriteMagic()
    {
        $this->specify(
            'Files session does not write data correctly with magic __set',
            function () {
                $I    = $this->tester;
                $path = PATH_OUTPUT . sprintf('tests%ssession%s', DIRECTORY_SEPARATOR, DIRECTORY_SEPARATOR);

                ini_set('session.save_handler', 'files');
                ini_set('session.save_path', $path);
                ini_set('session.serialize_handler', 'php');

                $session = new Files();
                $session->start();

                $session->some = 'write-magic-value';

                expect($id = $session->getId())->notEmpty();

                $file = sprintf('%ssess_%s', $path, $id);
                unset($session);

                $I->openFile($file);
                $I->seeInThisFile('some|s:17:"write-magic-value";');

                $I->deleteFile($file);
            }
        );
    }

    /**
     * Tests session read
     *
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-01-24
     */
    public function testSessionFilesRead()
    {
        $this->specify(
            'Files session does not read data correctly',
            function () {
                $I    = $this->tester;
                $id   = md5(microtime(true));
                $path = PATH_OUTPUT . sprintf('tests%ssession%s', DIRECTORY_SEPARATOR, DIRECTORY_SEPARATOR);
                $file = sprintf('%ssess_%s', $path, $id);

                $session = new Files();
                $session->setId($id);
                $session->start();

                $_SESSION['some'] = 'read-value';

                expect($session->has('some'))->true();
                expect($session->get('some'))->equals('read-value');

                $session->destroy();

                $I->dontSeeFileFound($file);
            }
        );
    }

    /**
     * Tests session read with magic __get
     *
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-01-24
     */
    public function testSessionFilesReadMagic()
    {
        $this->specify(
            'Files session does not read data correctly with magic __get',
            function () {
                $I    = $this->tester;
                $id   = md5(microtime(true));
                $path = PATH_OUTPUT . sprintf('tests%ssession%s', DIRECTORY_SEPARATOR, DIRECTORY_SEPARATOR);
                $file = sprintf('%ssess_%s', $path, $id);

                $session = new Files();
                $session->setId($id);
                $session->start();

                $_SESSION['some'] = 'read-magic-value';

                expect(isset($session->some))->true();
                expect($session->some)->equals('read-magic-value');

                unset($session->some);
                expect(isset($session->some))->false();

                $session->destroy();

                $I->dontSeeFileFound($file);
            }
        );
    }

    /**
     * Tests the destroy with cleanning $_SESSION
     *
     * @test
     * @issue  https://github.com/phalcon/cphalcon/issues/12326
     * @issue  https://github.com/phalcon/cphalcon/issues/12835
     * @author Serghei Iakovelev <serghei@phalconphp.com>
     * @since  2017-05-08
     */
    public function destroyDataFromSessionSuperGlobal()
    {
        $this->specify(
            'The files adapter does not clear session superglobal after destroy',
            function () {
                $session = new Files([
                    'uniqueId' => 'session',
                    'lifetime' => 3600,
                ]);

                $session->start();

                $session->test1 = __METHOD__;
                expect($_SESSION)->hasKey('session#test1');
                expect($_SESSION['session#test1'])->contains(__METHOD__);

                // @deprecated See: https://github.com/phalcon/cphalcon/issues/12833
                $session->destroy(true);
                expect($_SESSION)->hasntKey('session#test1');
            }
        );
    }
}
