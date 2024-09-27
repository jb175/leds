Import("env")

def before_build_action(source, target, env):
    env.Execute("pio run -t compiledb")

env.AddPreAction("buildprog", before_build_action)