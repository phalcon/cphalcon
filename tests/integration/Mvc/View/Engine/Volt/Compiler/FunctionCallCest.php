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

namespace Phalcon\Test\Integration\Mvc\View\Engine\Volt\Compiler;

use Codeception\Example;
use IntegrationTester;
use Phalcon\Mvc\View\Engine\Volt\Compiler;
use Phalcon\Test\Fixtures\Traits\DiTrait;

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

        $volt = new Compiler();

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
                '<?= $this->tag->linkTo([\'abc\']) ?>',
            ],
            [
                'image',
                '{{ image(\'abc\') }}',
                '<?= $this->tag->image([\'abc\']) ?>',
            ],
            [
                'form',
                '{{ form(\'abc\') }}',
                '<?= $this->tag->form([\'abc\']) ?>',
            ],
            [
                'submit_button',
                '{{ submit_button(\'abc\') }}',
                '<?= $this->tag->submitButton([\'abc\']) ?>',
            ],
            [
                'radio_field',
                '{{ radio_field(\'abc\') }}',
                '<?= $this->tag->radioField([\'abc\']) ?>',
            ],
            [
                'check_field',
                '{{ check_field(\'abc\') }}',
                '<?= $this->tag->checkField([\'abc\']) ?>',
            ],
            [
                'file_field',
                '{{ file_field(\'abc\') }}',
                '<?= $this->tag->fileField([\'abc\']) ?>',
            ],
            [
                'hidden_field',
                '{{ hidden_field(\'abc\') }}',
                '<?= $this->tag->hiddenField([\'abc\']) ?>',
            ],
            [
                'password_field',
                '{{ password_field(\'abc\') }}',
                '<?= $this->tag->passwordField([\'abc\']) ?>',
            ],
            [
                'text_area',
                '{{ text_area(\'abc\') }}',
                '<?= $this->tag->textArea([\'abc\']) ?>',
            ],
            [
                'text_field',
                '{{ text_field(\'abc\') }}',
                '<?= $this->tag->textField([\'abc\']) ?>',
            ],
            [
                'email_field',
                '{{ email_field(\'abc\') }}',
                '<?= $this->tag->emailField([\'abc\']) ?>',
            ],
            [
                'date_field',
                '{{ date_field(\'abc\') }}',
                '<?= $this->tag->dateField([\'abc\']) ?>',
            ],
            [
                'tel_field',
                '{{ tel_field(\'abc\') }}',
                '<?= $this->tag->telField([\'abc\']) ?>',
            ],
            [
                'numeric_field',
                '{{ numeric_field(\'abc\') }}',
                '<?= $this->tag->numericField([\'abc\']) ?>',
            ],
            [
                'image_input',
                '{{ image_input(\'abc\') }}',
                '<?= $this->tag->imageInput([\'abc\']) ?>',
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
                '<?= Phalcon\Version::get() ?>',
            ],
            [
                'version_id',
                '{{ version_id() }}',
                '<?= Phalcon\Version::getId() ?>',
            ],
            [
                'constant',
                '{{ constant(\'abc\') }}',
                '<?= constant(\'abc\') ?>',
            ],
            [
                'prefetch',
                '{{ prefetch(\'abc.css\') }}',
                '<?= $this->tag->prefetch(\'abc.css\') ?>',
            ],
            [
                'prefetch array',
                '{{ prefetch(\'abc.jpg\', [\'as\' : \'image\']) }}',
                '<?= $this->tag->prefetch(\'abc.jpg\', [\'as\' => \'image\']) ?>',
            ],
            [
                'somefunction',
                '{{ somefunction(\'abc\') }}',
                '<?= $this->callMacro(\'somefunction\', [\'abc\']) ?>',
            ],
        ];
    }
}
