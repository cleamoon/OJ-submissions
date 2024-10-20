import pandas as pd


def modifySalaryColumn(employees: pd.DataFrame) -> pd.DataFrame:
    employees["salary"] = employees["salary"].apply(lambda x: int(x) * 2)
    return employees
