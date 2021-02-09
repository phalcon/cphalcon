<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Zephir\Optimizers\FunctionCall;

use Zephir\Call;
use Zephir\CompilationContext;
use Zephir\CompiledExpression;
use Zephir\CompilerException;
use Zephir\HeadersManager;
use Zephir\Optimizers\OptimizerAbstract;

class PhannotParseAnnotationsOptimizer extends OptimizerAbstract
{
    /**
     * @param array              $expression
     * @param Call               $call
     * @param CompilationContext $context
     *
     * @return bool|CompiledExpression
     * @throws CompilerException
     */
    public function optimize(array $expression, Call $call, CompilationContext $context)
    {
        if (!isset($expression['parameters'])) {
            return false;
        }

        if (count($expression['parameters']) != 3) {
            throw new CompilerException(
                "phannot_parse_annotations only accepts three parameter",
                $expression
            );
        }

        /**
         * Process the expected symbol to be returned
         */
        $call->processExpectedReturn($context);

        $symbolVariable = $call->getSymbolVariable();

        if ($symbolVariable->getType() != 'variable') {
            throw new CompilerException(
                "Returned values by functions can only be assigned to variant variables",
                $expression
            );
        }

        if ($call->mustInitSymbolVariable()) {
            $symbolVariable->initVariant($context);
        }

        $context->headersManager->add(
            'phalcon/annotations/scanner',
            HeadersManager::POSITION_LAST
        );

        $context->headersManager->add(
            'phalcon/annotations/annot',
            HeadersManager::POSITION_LAST
        );

        $symbolVariable->setDynamicTypes('array');

        $resolvedParams = $call->getResolvedParams(
            $expression['parameters'],
            $context,
            $expression
        );

        $call->addCallStatusFlag($context);

        $symbol = $context->backend->getVariableCode($symbolVariable);

        $context->codePrinter->output(
            'ZEPHIR_LAST_CALL_STATUS = phannot_parse_annotations(' . $symbol . ', ' . $resolvedParams[0] . ', ' . $resolvedParams[1] . ', ' . $resolvedParams[2] . ');'
        );

        $call->checkTempParameters($context);
        $call->addCallStatusOrJump($context);

        return new CompiledExpression(
            'variable',
            $symbolVariable->getRealName(),
            $expression
        );
    }
}
