<?php
/**
 * InMemorySession.php
 * \Phalcon\Flash\Session\FlashSessionDefaultTest
 *
 * Tests Phalcon\Flash\Session
 *
 * PhalconPHP Framework
 *
 * @author    Iván Guillén <zeopix@gmail.com>
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */

namespace Phalcon\Tests\unit\Phalcon\Flash\Session;


use \PhalconTest\Flash\Session as PhFlash;

use \Phalcon\Tests\unit\Phalcon\_Helper\TestsBase as TBase;

use \Phalcon\DI as PhDI;


class FlashSessionDefaultTest extends TBase
{
    /**
     * @var array
     */
    protected $classes = [
        'success' => 'successMessage',
        'notice'  => 'noticeMessage',
        'warning' => 'warningMessage',
        'error'   => 'errorMessage',
    ];

    /**
     * Return flash instance
     */
    protected function getFlash()
    {
        $flash = new PhFlash($this->classes);
        $di = new PhDI();
        $di->set('session', new Helper\InMemorySession(), true);
        $flash->setDI($di);
        return $flash;
    }

    /**
     * Test getMessages with specified type and removal
     * activated, only removes the retreived messages.
     */
    public function testGetMessagesTypeRemoveMessages()
    {
        $flash = $this->getFlash();

        $flash->success('sample success');
        $flash->error('sample error');

        $expectedSuccessMessages = ['sample success'];
        $actualSuccessMessages = $flash->getMessages('success', true);
        expect($actualSuccessMessages)->equals($expectedSuccessMessages);

        $expectedErrorMessages = ['sample error'];
        $actualErrorMessages = $flash->getMessages('error', true);
        expect($actualErrorMessages)->equals($expectedErrorMessages);

        expect(null)->equals($flash->getMessages());
    }

    /**
     * Tests clear method
     */
    public function testClear()
    {
        $flash = $this->getFlash();

        ob_start();
        $flash->output();
        $flash->success('sample message');
        $flash->clear();
        $actual = ob_get_contents();
        ob_end_clean();
        $expected = '';

        expect($actual)->equals($expected);
    }

    /**
     * @dataProvider testStringDataProvider
     */
    public function testString($function)
    {
        $flash = $this->getFlash();
        $template = ' class="%s"';
        $class = sprintf($template, $this->classes[$function]);

        $template = '<div%s>%s</div>' . PHP_EOL;
        $message  = 'sample message';

        $expected = sprintf($template, $class, $message);
        ob_start();
        $flash->$function($message);
        $flash->output();
        $actual = ob_get_contents();
        ob_end_clean();

        expect($actual)->equals($expected);
    }


    /**
     * testString dataProvider
     */
    public function testStringDataProvider()
    {
        return array(
            'error' => array(
                'function' => 'error'
            ),
            'success' => array(
                'function' => 'success'
            ),
            'notice' => array(
                'function' => 'notice'
            )
        );
    }
}
