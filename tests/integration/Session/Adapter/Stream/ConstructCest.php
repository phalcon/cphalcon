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

use Codeception\Stub;
use IntegrationTester;
use Phalcon\Session\Adapter\Stream as SessionStream;
use Phalcon\Session\Exception;
use Phalcon\Tests\Fixtures\Traits\DiTrait;
use SessionHandlerInterface;

class ConstructCest
{
    use DiTrait;

    /**
     * Tests Phalcon\Session\Adapter\Stream :: __construct()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function sessionAdapterStreamConstruct(IntegrationTester $I)
    {
        $I->wantToTest('Session\Adapter\Stream - __construct()');

        $adapter = $this->newService('sessionStream');
        $class   = SessionHandlerInterface::class;
        $I->assertInstanceOf($class, $adapter);
    }

    /**
     * Tests Phalcon\Session\Adapter\Stream :: __construct() - empty session_path
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function sessionAdapterStreamConstructEmptySessionPath(IntegrationTester $I)
    {
        $I->wantToTest('Session\Adapter\Stream - __construct() - empty session path');

        $I->expectThrowable(
            new Exception('The session save path cannot be empty'),
            function () {
                $adapter = Stub::construct(
                    SessionStream::class,
                    [],
                    [
                        'phpIniGet' => '',
                    ]
                );
            }
        );
    }

    /**
     * Tests Phalcon\Session\Adapter\Stream :: __construct() - not writable path
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function sessionAdapterStreamConstructNotWritablePath(IntegrationTester $I)
    {
        $I->wantToTest('Session\Adapter\Stream - __construct() - not writable path');

        $path = ini_get('session.save_path');
        $I->expectThrowable(
            new Exception(
                'The session save path [' . $path . '] is not writable'
            ),
            function () {
                $adapter = Stub::construct(
                    SessionStream::class,
                    [],
                    [
                        'phpIsWritable' => false,
                    ]
                );
            }
        );
    }
}
