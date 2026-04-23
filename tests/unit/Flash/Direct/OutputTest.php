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

namespace Phalcon\Tests\Unit\Flash\Direct;

use Phalcon\Flash\Direct;
use Phalcon\Html\Escaper;
use Phalcon\Tests\AbstractUnitTestCase;

use function ob_end_clean;
use function ob_get_contents;
use function ob_start;

use const PHP_EOL;

final class OutputTest extends AbstractUnitTestCase
{
    /**
     * @return array[]
     */
    public static function getExamples(): array
    {
        $message     = 'sample <phalcon> message';
        $template    = '<div class="%cssClass%"><i class="%cssIconClass%"></i> %message%</div>';
        $classes     = [
            'error'   => 'errorPhalcon',
            'success' => 'successPhalcon',
            'notice'  => 'noticePhalcon',
            'warning' => 'warningPhalcon',
        ];
        $iconClasses = [
            'error'   => 'errorIconPhalcon',
            'success' => 'successIconPhalcon',
            'notice'  => 'noticeIconPhalcon',
            'warning' => 'warningIconPhalcon',
        ];

        // 'string/array message, classes,icon classes,html,escape,implicit,template',
        return [
            [
                $message,
                'sample <phalcon> message',
                [],
                [],
                false,
                false,
                false,
                '',
            ],
            [
                [$message, $message],
                'sample <phalcon> messagesample <phalcon> message',
                [],
                [],
                false,
                false,
                false,
                '',
            ],
            [
                $message,
                'sample <phalcon> message',
                [],
                [],
                false,
                false,
                false,
                $template,
            ],
            [
                [$message, $message],
                'sample <phalcon> messagesample <phalcon> message',
                [],
                [],
                false,
                false,
                false,
                $template,
            ],
            [
                $message,
                'sample <phalcon> message',
                [],
                [],
                false,
                false,
                true,
                '',
            ],
            [
                [$message, $message],
                'sample <phalcon> messagesample <phalcon> message',
                [],
                [],
                false,
                false,
                true,
                '',
            ],
            [
                $message,
                'sample &lt;phalcon&gt; message',
                [],
                [],
                false,
                true,
                false,
                '',
            ],
            [
                [$message, $message],
                'sample &lt;phalcon&gt; message'
                . 'sample &lt;phalcon&gt; message',
                [],
                [],
                false,
                true,
                false,
                '',
            ],
            [
                $message,
                '<div>sample <phalcon> message</div>'
                . PHP_EOL,
                [],
                [],
                true,
                false,
                false,
                '',
            ],
            [
                [$message, $message],
                '<div>sample <phalcon> message</div>'
                . PHP_EOL
                . '<div>sample <phalcon> message</div>'
                . PHP_EOL,
                [],
                [],
                true,
                false,
                false,
                '',
            ],
            [
                $message,
                'sample <phalcon> message',
                [],
                $iconClasses,
                false,
                false,
                false,
                '',
            ],
            [
                [$message, $message],
                'sample <phalcon> messagesample <phalcon> message',
                [],
                $iconClasses,
                false,
                false,
                false,
                '',
            ],
            [
                $message,
                'sample <phalcon> message',
                $classes,
                [],
                false,
                false,
                false,
                '',
            ],
            [
                [$message, $message],
                'sample <phalcon> messagesample <phalcon> message',
                $classes,
                [],
                false,
                false,
                false,
                '',
            ],
            [
                $message,
                'sample <phalcon> message',
                $classes,
                [],
                false,
                false,
                false,
                $template,
            ],
            [
                [$message, $message],
                'sample <phalcon> messagesample <phalcon> message',
                $classes,
                [],
                false,
                false,
                false,
                $template,
            ],
            [
                $message,
                'sample <phalcon> message',
                $classes,
                [],
                false,
                false,
                true,
                '',
            ],
            [
                [$message, $message],
                'sample <phalcon> messagesample <phalcon> message',
                $classes,
                [],
                false,
                false,
                true,
                '',
            ],
            [
                $message,
                'sample &lt;phalcon&gt; message',
                $classes,
                [],
                false,
                true,
                false,
                '',
            ],
            [
                [$message, $message],
                'sample &lt;phalcon&gt; message'
                . 'sample &lt;phalcon&gt; message',
                $classes,
                [],
                false,
                true,
                false,
                '',
            ],
            [
                $message,
                '<div class="successPhalcon">sample <phalcon> message</div>'
                . PHP_EOL,
                $classes,
                [],
                true,
                false,
                false,
                '',
            ],
            [
                [$message, $message],
                '<div class="successPhalcon">sample <phalcon> message</div>'
                . PHP_EOL
                . '<div class="successPhalcon">sample <phalcon> message</div>'
                . PHP_EOL,
                $classes,
                [],
                true,
                false,
                false,
                '',
            ],
            [
                $message,
                'sample <phalcon> message',
                $classes,
                $iconClasses,
                false,
                false,
                false,
                '',
            ],
            [
                [$message, $message],
                'sample <phalcon> messagesample <phalcon> message',
                $classes,
                $iconClasses,
                false,
                false,
                false,
                '',
            ],
            [
                $message,
                'sample <phalcon> message',
                $classes,
                $iconClasses,
                false,
                false,
                false,
                $template,
            ],
            [
                [$message, $message],
                'sample <phalcon> messagesample <phalcon> message',
                $classes,
                $iconClasses,
                false,
                false,
                false,
                $template,
            ],
            [
                $message,
                'sample <phalcon> message',
                $classes,
                $iconClasses,
                false,
                false,
                true,
                '',
            ],
            [
                [$message, $message],
                'sample <phalcon> messagesample <phalcon> message',
                $classes,
                $iconClasses,
                false,
                false,
                true,
                '',
            ],
            [
                $message,
                'sample &lt;phalcon&gt; message',
                $classes,
                $iconClasses,
                false,
                true,
                false,
                '',
            ],
            [
                [$message, $message],
                'sample &lt;phalcon&gt; message'
                . 'sample &lt;phalcon&gt; message',
                $classes,
                $iconClasses,
                false,
                true,
                false,
                '',
            ],
            [
                $message,
                '<div class="successPhalcon">'
                . '<i class="successIconPhalcon"></i> '
                . 'sample <phalcon> message</div>'
                . PHP_EOL,
                $classes,
                $iconClasses,
                true,
                false,
                false,
                '',
            ],
            [
                [$message, $message],
                '<div class="successPhalcon">'
                . '<i class="successIconPhalcon"></i> '
                . 'sample <phalcon> message</div>'
                . PHP_EOL
                . '<div class="successPhalcon">'
                . '<i class="successIconPhalcon"></i> '
                . 'sample <phalcon> message</div>'
                . PHP_EOL,
                $classes,
                $iconClasses,
                true,
                false,
                false,
                '',
            ],
            [
                $message,
                '<div class="successPhalcon">'
                . '<i class="successIconPhalcon"></i> '
                . 'sample <phalcon> message</div>',
                $classes,
                $iconClasses,
                true,
                false,
                false,
                $template,
            ],
            [
                [$message, $message],
                '<div class="successPhalcon">'
                . '<i class="successIconPhalcon"></i> '
                . 'sample <phalcon> message</div>'
                . '<div class="successPhalcon">'
                . '<i class="successIconPhalcon"></i> '
                . 'sample <phalcon> message</div>',
                $classes,
                $iconClasses,
                true,
                false,
                false,
                $template,
            ],
            [
                $message,
                '<div class="successPhalcon">'
                . '<i class="successIconPhalcon"></i> '
                . 'sample <phalcon> message</div>'
                . PHP_EOL,
                $classes,
                $iconClasses,
                true,
                false,
                true,
                '',
            ],
            [
                [$message, $message],
                '<div class="successPhalcon">'
                . '<i class="successIconPhalcon"></i> '
                . 'sample <phalcon> message</div>'
                . PHP_EOL
                . '<div class="successPhalcon">'
                . '<i class="successIconPhalcon"></i> '
                . 'sample <phalcon> message</div>'
                . PHP_EOL,
                $classes,
                $iconClasses,
                true,
                false,
                true,
                '',
            ],
            [
                $message,
                '<div class="successPhalcon">'
                . '<i class="successIconPhalcon"></i> '
                . 'sample &lt;phalcon&gt; message</div>'
                . PHP_EOL,
                $classes,
                $iconClasses,
                true,
                true,
                false,
                '',
            ],
            [
                [$message, $message],
                '<div class="successPhalcon">'
                . '<i class="successIconPhalcon"></i> '
                . 'sample &lt;phalcon&gt; message</div>'
                . PHP_EOL
                . '<div class="successPhalcon">'
                . '<i class="successIconPhalcon"></i> '
                . 'sample &lt;phalcon&gt; message</div>'
                . PHP_EOL,
                $classes,
                $iconClasses,
                true,
                true,
                false,
                '',
            ],
            [
                $message,
                '<div class="successPhalcon">'
                . '<i class="successIconPhalcon"></i> '
                . 'sample &lt;phalcon&gt; message</div>',
                $classes,
                $iconClasses,
                true,
                true,
                false,
                $template,
            ],
            [
                [$message, $message],
                '<div class="successPhalcon">'
                . '<i class="successIconPhalcon"></i> '
                . 'sample &lt;phalcon&gt; message</div>'
                . '<div class="successPhalcon">'
                . '<i class="successIconPhalcon"></i> '
                . 'sample &lt;phalcon&gt; message</div>',
                $classes,
                $iconClasses,
                true,
                true,
                false,
                $template,
            ],
            [
                $message,
                '<div class="successPhalcon">'
                . '<i class="successIconPhalcon"></i> '
                . 'sample &lt;phalcon&gt; message</div>'
                . PHP_EOL,
                $classes,
                $iconClasses,
                true,
                true,
                true,
                '',
            ],
            [
                [$message, $message],
                '<div class="successPhalcon">'
                . '<i class="successIconPhalcon"></i> '
                . 'sample &lt;phalcon&gt; message</div>'
                . PHP_EOL
                . '<div class="successPhalcon">'
                . '<i class="successIconPhalcon"></i> '
                . 'sample &lt;phalcon&gt; message</div>'
                . PHP_EOL,
                $classes,
                $iconClasses,
                true,
                true,
                true,
                '',
            ],
            [
                $message,
                '<div class="successPhalcon">'
                . '<i class="successIconPhalcon"></i> '
                . 'sample &lt;phalcon&gt; message</div>',
                $classes,
                $iconClasses,
                true,
                true,
                true,
                $template,
            ],
            [
                [$message, $message],
                '<div class="successPhalcon">'
                . '<i class="successIconPhalcon"></i> '
                . 'sample &lt;phalcon&gt; message</div>'
                . '<div class="successPhalcon">'
                . '<i class="successIconPhalcon"></i> '
                . 'sample &lt;phalcon&gt; message</div>',
                $classes,
                $iconClasses,
                true,
                true,
                true,
                $template,
            ],
        ];
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testFlashDirectOutput(): void
    {
        $flash = new Direct(new Escaper());
        $flash->setImplicitFlush(false);
        $flash->success('hello');
        $flash->warning('goodbye');

        ob_start();
        $flash->output(false);
        $actual = ob_get_contents();
        ob_end_clean();
        $expected = '<div class="successMessage">hello</div>' . PHP_EOL .
            '<div class="warningMessage">goodbye</div>' . PHP_EOL;
        $this->assertSame($expected, $actual);

        /**
         * remove them
         */
        ob_start();
        $flash->output();
        $actual = ob_get_contents();
        ob_end_clean();
        $expected = '<div class="successMessage">hello</div>' . PHP_EOL .
            '<div class="warningMessage">goodbye</div>' . PHP_EOL;
        $this->assertSame($expected, $actual);

        ob_start();
        $flash->output();
        $actual = ob_get_contents();
        ob_end_clean();
        $expected = '';
        $this->assertSame($expected, $actual);
    }

    /**
     * @dataProvider getExamples
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2020-09-09
     */
    public function testFlashDirectOutputCombinations(
        array | string $message,
        string $expected,
        array $classes,
        array $iconClasses,
        bool $autoHtml,
        bool $autoescape,
        bool $implicit,
        string $template
    ): void {
        $flash = new Direct(new Escaper());
        $flash
            ->setCssClasses($classes)
            ->setCssIconClasses($iconClasses)
            ->setAutomaticHtml($autoHtml)
            ->setAutoescape($autoescape)
            ->setCustomTemplate($template)
            ->setImplicitFlush($implicit)
        ;
        if (true === $implicit) {
            ob_start();
            $flash->outputMessage('success', $message);
            $actual = ob_get_contents();
            ob_end_clean();
        } else {
            $actual = $flash->outputMessage('success', $message);
        }

        $this->assertSame($expected, $actual);
    }
}
