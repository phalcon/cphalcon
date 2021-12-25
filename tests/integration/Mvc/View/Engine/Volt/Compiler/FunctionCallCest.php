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

namespace Phalcon\Tests\Integration\Mvc\View\Engine\Volt\Compiler;

use Codeception\Example;
use IntegrationTester;
use Phalcon\Mvc\View\Engine\Volt\Compiler;
use Phalcon\Tests\Fixtures\Traits\DiTrait;

/**
 * Class FunctionCallCest
 */
class FunctionCallCest
{
    use DiTrait;

    /**
     * Tests Phalcon\Mvc\View\Engine\Volt\Compiler :: functionCall()
     *
     * @param IntegrationTester $I
     * @param Example           $example
     *
     * @dataProvider getExamples
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2020-01-11
     */
    public function mvcViewEngineVoltCompilerFunctionCall(IntegrationTester $I, Example $example)
    {
        $I->wantToTest('Mvc\View\Engine\Volt\Compiler - functionCall() ' . $example[0]);

        $this->setNewFactoryDefault();

        $volt = new Compiler();
        $volt->setDI($this->container);

        $expected = $example[2];
        $actual   = $volt->compileString($example[1]);

        $I->assertEquals($expected, $actual);
    }

    /**
     * @return array
     */
    private function getExamples(): array
    {
        return [
            [
                'get_content',
                '{{ content() }}',
                '<?= $this->getContent() ?>',
            ],
            [
                'content',
                '{{ content() }}',
                '<?= $this->getContent() ?>',
            ],
            [
                'partial',
                '{{ partial("abc.volt") }}',
                '<?= $this->partial(\'abc.volt\') ?>',
            ],
            [
                'link_to',
                '{{ link_to(\'abc\') }}',
                '<?= \Phalcon\Tag::linkTo([\'abc\']) ?>',
            ],
            [
                'image',
                '{{ image(\'abc\') }}',
                '<?= \Phalcon\Tag::image([\'abc\']) ?>',
            ],
            [
                'form',
                '{{ form(\'abc\') }}',
                '<?= \Phalcon\Tag::form([\'abc\']) ?>',
            ],
            [
                'submit_button',
                '{{ submit_button(\'abc\') }}',
                '<?= \Phalcon\Tag::submitButton([\'abc\']) ?>',
            ],
            [
                'radio_field',
                '{{ radio_field(\'abc\') }}',
                '<?= \Phalcon\Tag::radioField([\'abc\']) ?>',
            ],
            [
                'check_field',
                '{{ check_field(\'abc\') }}',
                '<?= \Phalcon\Tag::checkField([\'abc\']) ?>',
            ],
            [
                'file_field',
                '{{ file_field(\'abc\') }}',
                '<?= \Phalcon\Tag::fileField([\'abc\']) ?>',
            ],
            [
                'hidden_field',
                '{{ hidden_field(\'abc\') }}',
                '<?= \Phalcon\Tag::hiddenField([\'abc\']) ?>',
            ],
            [
                'password_field',
                '{{ password_field(\'abc\') }}',
                '<?= \Phalcon\Tag::passwordField([\'abc\']) ?>',
            ],
            [
                'text_area',
                '{{ text_area(\'abc\') }}',
                '<?= \Phalcon\Tag::textArea([\'abc\']) ?>',
            ],
            [
                'text_field',
                '{{ text_field(\'abc\') }}',
                '<?= \Phalcon\Tag::textField([\'abc\']) ?>',
            ],
            [
                'email_field',
                '{{ email_field(\'abc\') }}',
                '<?= \Phalcon\Tag::emailField([\'abc\']) ?>',
            ],
            [
                'date_field',
                '{{ date_field(\'abc\') }}',
                '<?= \Phalcon\Tag::dateField([\'abc\']) ?>',
            ],
            [
                'tel_field',
                '{{ tel_field(\'abc\') }}',
                '<?= \Phalcon\Tag::telField([\'abc\']) ?>',
            ],
            [
                'numeric_field',
                '{{ numeric_field(\'abc\') }}',
                '<?= \Phalcon\Tag::numericField([\'abc\']) ?>',
            ],
            [
                'image_input',
                '{{ image_input(\'abc\') }}',
                '<?= \Phalcon\Tag::imageInput([\'abc\']) ?>',
            ],
            [
                'url',
                '{{ url(\'abc\') }}',
                '<?= $this->url->get(\'abc\') ?>',
            ],
            [
                'static_url',
                '{{ static_url(\'abc\') }}',
                '<?= $this->url->getStatic(\'abc\') ?>',
            ],
            [
                'date',
                '{{ date(\'abc\') }}',
                '<?= date(\'abc\') ?>',
            ],
            [
                'time',
                '{{ time() }}',
                '<?= time() ?>',
            ],
            [
                'dump',
                '{{ dump(\'abc\') }}',
                '<?= var_dump(\'abc\') ?>',
            ],
            [
                'version',
                '{{ version() }}',
                '<?= (new Phalcon\Support\Version)->get() ?>',
            ],
            [
                'version_id',
                '{{ version_id() }}',
                '<?= (new Phalcon\Support\Version)->getId() ?>',
            ],
            [
                'constant',
                '{{ constant(\'abc\') }}',
                '<?= constant(\'abc\') ?>',
            ],
            [
                'preload',
                '{{ preload(\'abc.css\') }}',
                '<?= $this->preload(\'abc.css\') ?>',
            ],
            [
                'preload array',
                '{{ preload(\'abc.jpg\', [\'as\' : \'image\']) }}',
                '<?= $this->preload(\'abc.jpg\', [\'as\' => \'image\']) ?>',
            ],
            [
                'somefunction',
                '{{ somefunction(\'abc\') }}',
                '<?= $this->callMacro(\'somefunction\', [\'abc\']) ?>',
            ],
        ];
    }
}
