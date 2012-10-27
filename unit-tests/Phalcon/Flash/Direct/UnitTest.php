<?php
/**
 * UnitTest.php
 * \Phalcon\Flash\Direct\UnitTest
 *
 * Tests the \Phalcon\Flash\Direct component
 *
 * PhalconPHP Framework
 *
 * @copyright (c) 2011-2012 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Eduar Carvajal <eduar@phalconphp.com>
 * @author    Nikolaos Dimopoulos <nikos@niden.net>
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */

use \Phalcon\Flash\Direct as Flash;

class Flash_Direct_UnitTest extends \PhalconUnitTestCase
{
    /**
     * Tests error (implicit flush)
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-09-30
     */
    public function testErrorStringImplicitFlushHtml()
    {
        $flash = new Flash();

        $message = 'sample message';

        ob_start();
        $flash->error($message);
        $actual = ob_get_contents();
        ob_end_clean();

        $expected = '<div class="errorMessage">sample message</div>' . PHP_EOL;

        $this->assertEquals(
            $expected,
            $actual,
            'Flash\Direct error does not produce the correct HTML'
        );
    }

    /**
     * Tests success (implicit flush)
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-09-30
     */
    public function testSuccessStringImplicitFlushHtml()
    {
        $flash = new Flash();

        $message = 'sample message';

        ob_start();
        $flash->success($message);
        $actual = ob_get_contents();
        ob_end_clean();

        $expected = '<div class="successMessage">sample message</div>' . PHP_EOL;

        $this->assertEquals(
            $expected,
            $actual,
            'Flash\Direct success does not produce the correct HTML'
        );
    }

    /**
     * Tests notice (implicit flush)
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-09-30
     */
    public function testNoticeStringImplicitFlushHtml()
    {
        $flash = new Flash();

        $message = 'sample message';

        ob_start();
        $flash->notice($message);
        $actual = ob_get_contents();
        ob_end_clean();

        $expected = '<div class="noticeMessage">sample message</div>' . PHP_EOL;

        $this->assertEquals(
            $expected,
            $actual,
            'Flash\Direct notice does not produce the correct HTML'
        );
    }

    /**
     * Tests warning (implicit flush)
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-09-30
     */
    public function testWarningStringImplicitFlushHtml()
    {
        $flash = new Flash();

        $message = 'sample message';

        ob_start();
        $flash->warning($message);
        $actual = ob_get_contents();
        ob_end_clean();

        $expected = '<div class="warningMessage">sample message</div>' . PHP_EOL;

        $this->assertEquals(
            $expected,
            $actual,
            'Flash\Direct warning does not produce the correct HTML'
        );
    }

    /**
     * Tests error array of messages (implicit flush)
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-09-30
     */
    public function testErrorArrayImplicitFlushHtml()
    {
        $flash = new Flash();

        $message = array(
                    'sample message 1',
                    'sample message 2',
                   );

        ob_start();
        $flash->error($message);
        $actual = ob_get_contents();
        ob_end_clean();

        $expected = '<div class="errorMessage">sample message 1</div>' . PHP_EOL
                  . '<div class="errorMessage">sample message 2</div>' . PHP_EOL;

        $this->assertEquals(
            $expected,
            $actual,
            'Flash\Direct error does not produce the correct HTML'
        );
    }

    /**
     * Tests success array of messages (implicit flush)
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-09-30
     */
    public function testSuccessArrayImplicitFlushHtml()
    {
        $flash = new Flash();

        $message = array(
                    'sample message 1',
                    'sample message 2',
                   );

        ob_start();
        $flash->success($message);
        $actual = ob_get_contents();
        ob_end_clean();

        $expected = '<div class="successMessage">sample message 1</div>' . PHP_EOL
                  . '<div class="successMessage">sample message 2</div>' . PHP_EOL;

        $this->assertEquals(
            $expected,
            $actual,
            'Flash\Direct success does not produce the correct HTML'
        );
    }

    /**
     * Tests notice array of messages (implicit flush)
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-09-30
     */
    public function testNoticeArrayImplicitFlushHtml()
    {
        $flash = new Flash();

        $message = array(
                    'sample message 1',
                    'sample message 2',
                   );

        ob_start();
        $flash->notice($message);
        $actual = ob_get_contents();
        ob_end_clean();

        $expected = '<div class="noticeMessage">sample message 1</div>' . PHP_EOL
                  . '<div class="noticeMessage">sample message 2</div>' . PHP_EOL;

        $this->assertEquals(
            $expected,
            $actual,
            'Flash\Direct notice does not produce the correct HTML'
        );
    }

    /**
     * Tests warning array of messages (implicit flush)
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-09-30
     */
    public function testWarningArrayImplicitFlushHtml()
    {
        $flash = new Flash();

        $message = array(
                    'sample message 1',
                    'sample message 2',
                   );

        ob_start();
        $flash->warning($message);
        $actual = ob_get_contents();
        ob_end_clean();

        $expected = '<div class="warningMessage">sample message 1</div>' . PHP_EOL
                  . '<div class="warningMessage">sample message 2</div>' . PHP_EOL;

        $this->assertEquals(
            $expected,
            $actual,
            'Flash\Direct warning does not produce the correct HTML'
        );
    }

    /**
     * Tests error (no implicit flush)
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-09-30
     */
    public function testErrorStringNoImplicitFlushHtml()
    {
        $flash = new Flash();
        $flash->setImplicitFlush(false);

        $message = 'sample message';

        $actual   = $flash->error($message);
        $expected = '<div class="errorMessage">sample message</div>' . PHP_EOL;

        $this->assertEquals(
            $expected,
            $actual,
            'Flash\Direct error does not produce the correct HTML'
        );
    }

    /**
     * Tests success (no implicit flush)
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-09-30
     */
    public function testSuccessStringNoImplicitFlushHtml()
    {
        $flash = new Flash();
        $flash->setImplicitFlush(false);

        $message = 'sample message';

        $actual   = $flash->success($message);
        $expected = '<div class="successMessage">sample message</div>' . PHP_EOL;

        $this->assertEquals(
            $expected,
            $actual,
            'Flash\Direct success does not produce the correct HTML'
        );
    }

    /**
     * Tests notice (no implicit flush)
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-09-30
     */
    public function testNoticeStringNoImplicitFlushHtml()
    {
        $flash = new Flash();
        $flash->setImplicitFlush(false);

        $message = 'sample message';

        $actual   = $flash->notice($message);
        $expected = '<div class="noticeMessage">sample message</div>' . PHP_EOL;

        $this->assertEquals(
            $expected,
            $actual,
            'Flash\Direct notice does not produce the correct HTML'
        );
    }

    /**
     * Tests warning (no implicit flush)
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-09-30
     */
    public function testWarningStringNoImplicitFlushHtml()
    {
        $flash = new Flash();
        $flash->setImplicitFlush(false);

        $message = 'sample message';

        $actual   = $flash->warning($message);
        $expected = '<div class="warningMessage">sample message</div>' . PHP_EOL;

        $this->assertEquals(
            $expected,
            $actual,
            'Flash\Direct warning does not produce the correct HTML'
        );
    }

    /**
     * Tests error array of messages (no implicit flush)
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-09-30
     */
    public function testErrorArrayNoImplicitFlushHtml()
    {
        $flash = new Flash();
        $flash->setImplicitFlush(false);

        $message = array(
            'sample message 1',
            'sample message 2',
        );

        $actual   = $flash->error($message);
        $expected = '<div class="errorMessage">sample message 1</div>' . PHP_EOL
                  . '<div class="errorMessage">sample message 2</div>' . PHP_EOL;

        $this->assertEquals(
            $expected,
            $actual,
            'Flash\Direct error does not produce the correct HTML'
        );
    }

    /**
     * Tests success array of messages (no implicit flush)
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-09-30
     */
    public function testSuccessArrayNoImplicitFlushHtml()
    {
        $flash = new Flash();
        $flash->setImplicitFlush(false);

        $message = array(
            'sample message 1',
            'sample message 2',
        );

        $actual   = $flash->success($message);
        $expected = '<div class="successMessage">sample message 1</div>' . PHP_EOL
                  . '<div class="successMessage">sample message 2</div>' . PHP_EOL;

        $this->assertEquals(
            $expected,
            $actual,
            'Flash\Direct success does not produce the correct HTML'
        );
    }

    /**
     * Tests notice array of messages (no implicit flush)
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-09-30
     */
    public function testNoticeArrayNoImplicitFlushHtml()
    {
        $flash = new Flash();
        $flash->setImplicitFlush(false);

        $message = array(
            'sample message 1',
            'sample message 2',
        );

        $actual   = $flash->notice($message);
        $expected = '<div class="noticeMessage">sample message 1</div>' . PHP_EOL
                  . '<div class="noticeMessage">sample message 2</div>' . PHP_EOL;

        $this->assertEquals(
            $expected,
            $actual,
            'Flash\Direct notice does not produce the correct HTML'
        );
    }

    /**
     * Tests warning array of messages (no implicit flush)
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-09-30
     */
    public function testWarningArrayNoImplicitFlushHtml()
    {
        $flash = new Flash();
        $flash->setImplicitFlush(false);

        $message = array(
            'sample message 1',
            'sample message 2',
        );

        $actual   = $flash->warning($message);
        $expected = '<div class="warningMessage">sample message 1</div>' . PHP_EOL
                  . '<div class="warningMessage">sample message 2</div>' . PHP_EOL;

        $this->assertEquals(
            $expected,
            $actual,
            'Flash\Direct warning does not produce the correct HTML'
        );
    }

    /**
     * Tests error (implicit flush no html)
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-09-30
     */
    public function testErrorStringImplicitFlushNoHtml()
    {
        $flash = new Flash();
        $flash->setAutomaticHtml(false);

        $message = 'sample message';

        ob_start();
        $flash->error($message);
        $actual = ob_get_contents();
        ob_end_clean();

        $expected = 'sample message';

        $this->assertEquals(
            $expected,
            $actual,
            'Flash\Direct error does not produce the correct message'
        );
    }

    /**
     * Tests success (implicit flush no html)
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-09-30
     */
    public function testSuccessStringImplicitFlushNoHtml()
    {
        $flash = new Flash();
        $flash->setAutomaticHtml(false);

        $message = 'sample message';

        ob_start();
        $flash->success($message);
        $actual = ob_get_contents();
        ob_end_clean();

        $expected = 'sample message';

        $this->assertEquals(
            $expected,
            $actual,
            'Flash\Direct success does not produce the correct message'
        );
    }

    /**
     * Tests notice (implicit flush no html)
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-09-30
     */
    public function testNoticeStringImplicitFlushNoHtml()
    {
        $flash = new Flash();
        $flash->setAutomaticHtml(false);

        $message = 'sample message';

        ob_start();
        $flash->notice($message);
        $actual = ob_get_contents();
        ob_end_clean();

        $expected = 'sample message';

        $this->assertEquals(
            $expected,
            $actual,
            'Flash\Direct notice does not produce the correct message'
        );
    }

    /**
     * Tests warning (implicit flush no html)
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-09-30
     */
    public function testWarningStringImplicitFlushNoHtml()
    {
        $flash = new Flash();
        $flash->setAutomaticHtml(false);

        $message = 'sample message';

        ob_start();
        $flash->warning($message);
        $actual = ob_get_contents();
        ob_end_clean();

        $expected = 'sample message';

        $this->assertEquals(
            $expected,
            $actual,
            'Flash\Direct warning does not produce the correct message'
        );
    }

    /**
     * Tests error array of messages (implicit flush no html)
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-09-30
     */
    public function testErrorArrayImplicitFlushNoHtml()
    {
        $flash = new Flash();
        $flash->setAutomaticHtml(false);

        $message = array(
            'sample message 1',
            'sample message 2',
        );

        ob_start();
        $flash->error($message);
        $actual = ob_get_contents();
        ob_end_clean();

        $expected = 'sample message 1'
                  . 'sample message 2';

        $this->assertEquals(
            $expected,
            $actual,
            'Flash\Direct error does not produce the correct message'
        );
    }

    /**
     * Tests success array of messages (implicit flush no html)
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-09-30
     */
    public function testSuccessArrayImplicitFlushNoHtml()
    {
        $flash = new Flash();
        $flash->setAutomaticHtml(false);

        $message = array(
            'sample message 1',
            'sample message 2',
        );

        ob_start();
        $flash->success($message);
        $actual = ob_get_contents();
        ob_end_clean();

        $expected = 'sample message 1'
                  . 'sample message 2';

        $this->assertEquals(
            $expected,
            $actual,
            'Flash\Direct success does not produce the correct message'
        );
    }

    /**
     * Tests notice array of messages (implicit flush no html)
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-09-30
     */
    public function testNoticeArrayImplicitFlushNoHtml()
    {
        $flash = new Flash();
        $flash->setAutomaticHtml(false);

        $message = array(
            'sample message 1',
            'sample message 2',
        );

        ob_start();
        $flash->notice($message);
        $actual = ob_get_contents();
        ob_end_clean();

        $expected = 'sample message 1'
                  . 'sample message 2';

        $this->assertEquals(
            $expected,
            $actual,
            'Flash\Direct notice does not produce the correct message'
        );
    }

    /**
     * Tests warning array of messages (implicit flush no html)
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-09-30
     */
    public function testWarningArrayImplicitFlushNoHtml()
    {
        $flash = new Flash();
        $flash->setAutomaticHtml(false);

        $message = array(
            'sample message 1',
            'sample message 2',
        );

        ob_start();
        $flash->warning($message);
        $actual = ob_get_contents();
        ob_end_clean();

        $expected = 'sample message 1'
                  . 'sample message 2';

        $this->assertEquals(
            $expected,
            $actual,
            'Flash\Direct warning does not produce the correct message'
        );
    }

    /**
     * Tests error (no implicit flush no html)
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-09-30
     */
    public function testErrorStringNoImplicitFlushNoHtml()
    {
        $flash = new Flash();
        $flash->setImplicitFlush(false);
        $flash->setAutomaticHtml(false);

        $message = 'sample message';

        $actual   = $flash->error($message);
        $expected = 'sample message';

        $this->assertEquals(
            $expected,
            $actual,
            'Flash\Direct error does not produce the correct message'
        );
    }

    /**
     * Tests success (no implicit flush no html)
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-09-30
     */
    public function testSuccessStringNoImplicitFlushNoHtml()
    {
        $flash = new Flash();
        $flash->setImplicitFlush(false);
        $flash->setAutomaticHtml(false);

        $message = 'sample message';

        $actual   = $flash->success($message);
        $expected = 'sample message';

        $this->assertEquals(
            $expected,
            $actual,
            'Flash\Direct success does not produce the correct message'
        );
    }

    /**
     * Tests notice (no implicit flush no html)
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-09-30
     */
    public function testNoticeStringNoImplicitFlushNoHtml()
    {
        $flash = new Flash();
        $flash->setImplicitFlush(false);
        $flash->setAutomaticHtml(false);

        $message = 'sample message';

        $actual   = $flash->notice($message);
        $expected = 'sample message';

        $this->assertEquals(
            $expected,
            $actual,
            'Flash\Direct notice does not produce the correct message'
        );
    }

    /**
     * Tests warning (no implicit flush no html)
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-09-30
     */
    public function testWarningStringNoImplicitFlushNoHtml()
    {
        $flash = new Flash();
        $flash->setImplicitFlush(false);
        $flash->setAutomaticHtml(false);

        $message = 'sample message';

        $actual   = $flash->warning($message);
        $expected = 'sample message';

        $this->assertEquals(
            $expected,
            $actual,
            'Flash\Direct warning does not produce the correct message'
        );
    }

    /**
     * Tests error array of messages (no implicit flush no html)
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-09-30
     */
    public function testErrorArrayNoImplicitFlushNoHtml()
    {
        $flash = new Flash();
        $flash->setImplicitFlush(false);
        $flash->setAutomaticHtml(false);

        $message = array(
            'sample message 1',
            'sample message 2',
        );

        $actual   = $flash->error($message);
        $expected = 'sample message 1'
                  . 'sample message 2';

        $this->assertEquals(
            $expected,
            $actual,
            'Flash\Direct error does not produce the correct message'
        );
    }

    /**
     * Tests success array of messages (no implicit flush no html)
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-09-30
     */
    public function testSuccessArrayNoImplicitFlushNoHtml()
    {
        $flash = new Flash();
        $flash->setImplicitFlush(false);
        $flash->setAutomaticHtml(false);

        $message = array(
            'sample message 1',
            'sample message 2',
        );

        $actual   = $flash->success($message);
        $expected = 'sample message 1'
                  . 'sample message 2';

        $this->assertEquals(
            $expected,
            $actual,
            'Flash\Direct success does not produce the correct message'
        );
    }

    /**
     * Tests notice array of messages (no implicit flush no html)
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-09-30
     */
    public function testNoticeArrayNoImplicitFlushNoHtml()
    {
        $flash = new Flash();
        $flash->setImplicitFlush(false);
        $flash->setAutomaticHtml(false);

        $message = array(
            'sample message 1',
            'sample message 2',
        );

        $actual   = $flash->notice($message);
        $expected = 'sample message 1'
                  . 'sample message 2';

        $this->assertEquals(
            $expected,
            $actual,
            'Flash\Direct notice does not produce the correct message'
        );
    }

    /**
     * Tests warning array of messages (no implicit flush no html)
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-09-30
     */
    public function testWarningArrayNoImplicitFlushNoHtml()
    {
        $flash = new Flash();
        $flash->setImplicitFlush(false);
        $flash->setAutomaticHtml(false);

        $message = array(
            'sample message 1',
            'sample message 2',
        );

        $actual   = $flash->warning($message);
        $expected = 'sample message 1'
                  . 'sample message 2';

        $this->assertEquals(
            $expected,
            $actual,
            'Flash\Direct warning does not produce the correct message'
        );
    }

    public function testFlashDirectCssClasses()
    {

        $this->markTestSkipped('Need work on the Flash Direct CSS classes');
        $messageText = 'sample message';

        $flash = new Phalcon\Flash\Direct(array(
            'error' => 'alert alert-error',
            'success' => 'alert alert-success',
            'notice' => 'alert alert-notice',
            'warning' => 'alert alert-warning'
        ));

        ob_start();
        $flash->error($messageText);
        $flash->success($messageText);
        $flash->notice($messageText);
        $flash->warning($messageText);
        $content = ob_get_contents();
        ob_end_clean();

        $this->assertEquals($content,
            '<div class="alert alert-error">sample message</div>'.PHP_EOL.
                '<div class="alert alert-success">sample message</div>'.PHP_EOL.
                '<div class="alert alert-notice">sample message</div>'.PHP_EOL.
                '<div class="alert alert-warning">sample message</div>'.PHP_EOL
        );

    }
}
